
#include <iostream>


using namespace std;

void num_pr() {
        cout << "Выйди и зайди ты уже нормально "<< endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int main()
{
    setlocale(LC_ALL,"ru");

    int n, imax = 0, jmax = 0;

    do {
        cout << "Введите размерность больше нуля и меньше 10"; 
        cin >> n;
        while ((cin.get() != '\n' && cin.get() != ' ') || !cin) {
            num_pr();
            cin >> n;
        }
    } while (n < 0 || n>10);

    cout << "Хорош"<< endl;
    // заведение динамического 2 мерного массива
    int **a = new int* [n]; 
    for (int k = 0; k < n; k++) {
        a[k] = new int [n];
    }
    // чтение массива введенного пользователем
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        } 
    }
    
    //обработка: поиск максимального элемента
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > a[imax][jmax]) {
                imax = i;
                jmax = j;
            }
        }
    }
    cout << imax << "\t" << jmax << endl;

    // замена элементов строки с макс. элементом на элементы следующей
    for (int i = imax; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = a[i + 1][j];
        }
       
    }
    
    // замена элементов столбца с макс. элементом на элементы следующего
    for (int i = 0; i < n; i++) {
        for (int j = jmax; j < n - 1; j++) {
            a[i][j] = a[i][j + 1];
        }

    }

    cout << "==========" << endl;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // очищение занятой памяти
    for (int k = 0; k < n; k++) {
        delete[] a[k];
    }
    delete[]a;

    a = NULL;
    return 0;
}

