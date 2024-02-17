#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

using namespace std;

const int BUFFER_SIZE = 10;
const string FILENAME = "output.txt";

// Глобальные переменные
sem_t* semaphore;
vector<int> buffer;

// Функция для генерации случайных чисел и помещения их в буфер
void fillBuffer() {
    srand(time(NULL));
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        buffer.push_back(rand() % 100);
    }
}

// Процесс p1
void p1() {
    while (true) {
        sem_wait(semaphore); // Захват семафора

        if (!buffer.empty()) {
            int randomIndex = rand() % buffer.size();
            int randomNumber = buffer[randomIndex];
            cout << "p1: " << randomNumber << endl;
            buffer.erase(buffer.begin() + randomIndex);
        }

        sem_post(semaphore); // Освобождение семафора
        sleep(1);
    }
}

// Процесс p2
void p2() {
    ofstream outputFile(FILENAME);

    while (true) {
        sem_wait(semaphore); // Захват семафора

        if (!buffer.empty()) {
            int randomIndex = rand() % buffer.size();
            int randomNumber = buffer[randomIndex];
            cout << "p2: " << randomNumber << " (writing to file)" << endl;
            buffer.erase(buffer.begin() + randomIndex);
            outputFile << randomNumber << " ";
        }

        sem_post(semaphore); // Освобождение семафора
        sleep(1);
    }

    outputFile.close();
}

int main() {
    fillBuffer();

    semaphore = sem_open("/my_semaphore", O_CREAT, 0644, 1);
    if (semaphore == SEM_FAILED) {
        cerr << "Failed to create semaphore" << endl;
        return 1;
    }

    pid_t pid1 = fork();
    if (pid1 == 0) {
        p1(); // Процесс p1
        return 0;
    } else if (pid1 < 0) {
        cerr << "Failed to fork process p1" << endl;
        return 1;
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        p2(); // Процесс p2
        return 0;
    } else if (pid2 < 0) {
        cerr << "Failed to fork process p2" << endl;
        return 1;
    }

    // Ожидание завершения обоих процессов
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    sem_destroy(semaphore); // Уничтожение семафора
    buffer.clear(); // Очистка буфера

    return 0;
}
