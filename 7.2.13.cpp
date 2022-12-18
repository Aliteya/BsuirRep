#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <io.h>


using namespace std;

struct stud{
	char surname[20] = "";
	int num = 0;
	int fiz = 0;
	int mat = 0;
	int inf = 0;
	double srball = 0;
};
void filefill() {
	char path[70];
	cout<< "Введите путь" << endl;
	cin >> path;
	
	stud student;
	FILE* my_file;
	fopen_s(&my_file, path, "wb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	char v;
	do {
		cout << "Введите фамилию" << endl;
		cin >> student.surname;
		cout << "Введите номер группы" << endl;
		cin >> student.num;
		cout << "Введите оценку по физике" << endl;
		cin >> student.fiz;
		cout << "Введите оценку по матеше" << endl;
		cin >> student.mat;
		cout << "Введите оценку по инфе" << endl;
		cin >> student.inf;
	    
		student.srball = (student.fiz + student.mat + student.inf) / 3.;
		fwrite(&student, sizeof(stud), 1, my_file);
		cout << "Введите 1, чтобы продолжить, 2 - чтобы остановить";
		cin >> v;
	} while ( v != '2');
	fclose(my_file);
}

void fileread() {
	char path[70];
	cout << "Введите путь" << endl;
	cin >> path;
	stud* student;
	FILE* my_file;
	fopen_s(&my_file, path, "rb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	int n = _filelength(_fileno(my_file)) / sizeof(stud);
	student = new stud[n];
	cout << n;
	fread(student, sizeof(stud), n, my_file);
	for (int i = 0; i < n; i++) {
		cout << "Студент номер " << i + 1 << endl;
		cout << "Фамилия: "  << student[i].surname << endl;
		cout << "Номер группы: "  << student[i].num << endl;
		cout << "Оценка по физике: "  << student[i].fiz << endl;
		cout << "Оценка по матеше: "  << student[i].mat << endl;
		cout << "Оценка по инфе: "  << student[i].inf << endl;
	}
	delete[] student;
	fclose(my_file);
}

void fsort() {
	char path[70];
	cout << "Введите путь" << endl;
	cin >> path;
	stud* student;
	FILE* my_file;
	fopen_s(&my_file, path, "rb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	int n = _filelength(_fileno(my_file)) / sizeof(stud);
	student = new stud[n];
	cout << n;
	fread(student, sizeof(stud), n, my_file);
	int k;
	cout << "Выберите сортировку 1- по среднему баллу 2 - по фамилиям";
	cin >> k;
	switch (k) {
	case 1: 
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if ( student[i].srball < student[j].srball)
				swap(student[i], student[j]);
			}
		}

		for (int i = 0; i < n; i++) {
			cout << "Студент номер " << i + 1 << endl;
			cout << "Фамилия: " << student[i].surname << endl;
			cout << "Номер группы: " << student[i].num << endl;
			cout << "Оценка по физике: " << student[i].fiz << endl;
			cout << "Оценка по матеше: " << student[i].mat << endl;
			cout << "Оценка по инфе: " << student[i].inf << endl;
		}

	 break;

	case 2: 
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (strcmp(student[i].surname, student[j].surname) == true)
					swap(student[i], student[j]);
			}
		}

		for (int i = 0; i < n; i++) {
			cout << "Студент номер " << i + 1 << endl;
			cout << "Фамилия: " << student[i].surname << endl;
			cout << "Номер группы: " << student[i].num << endl;
			cout << "Оценка по физике: " << student[i].fiz << endl;
			cout << "Оценка по матеше: " << student[i].mat << endl;
			cout << "Оценка по инфе: " << student[i].inf << endl;
		}

	 break;
	}
	delete[] student;
	fclose(my_file);
}

void filetask() {
	char path[70], respath[70];
	cout << "Введите путь" << endl;
	cin >> path;
	cout << "Введите путь выходного файла" << endl;
	cin >> respath;
	stud* student;
	FILE* my_file;
	FILE* res_file;
	fopen_s(&my_file, path, "rb");
	fopen_s(&res_file, respath, "w");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	if (!res_file) {
		cout << "еррор" << endl;
		return;
	}

	int n = _filelength(_fileno(my_file)) / sizeof(stud);
	student = new stud[n];
	double sum = 0, sr; 
	fread(student, sizeof(stud), n, my_file);
	for (int i = 0; i < n; i++) {
		sum += student[i].srball;
	}
	sr = sum / n;
	fprintf(res_file, "Средний балл по списку - %f \n", sr);
	for (int i = 0; i < n; i++) {
		if (student[i].srball > sr) {
		 fprintf(res_file, "Фамилия - %s \n Номер группы - %d \n Оценка по физике - %d \n Оценка по мaтеше - %d \n Оценка по инфе - %d \n", student[i].surname, student[i].num, student[i].fiz, student[i].mat, student[i].inf);
		}
	}
	delete[] student;
	
	fclose(my_file);
	fclose(res_file);
}

int main()
{

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choise, opr = 1;
	while (opr) {
	cout << "Выберите" << endl;
	cout << "1. Создать и записать" << endl;
	cout << "2. Считать" << endl;
	cout << "3. Сортировать" << endl;
	cout << "4. Индивидуалка" << endl;

	cin >> choise; 
	switch (choise) {
	case 1:  filefill();  break;
	case 2:  fileread();  break;
	case 3:  fsort(); break;
	case 4: filetask(); break;
	}
	}
	return 0;
}
