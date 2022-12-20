#include <iostream>
#include <Windows.h>
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

void filefill();
void fileread();
void fsort();
void filetask();
void filedel();
void update();

int main()
{

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choise;
	bool opr = 1;
	while (opr) {
	cout << "Выберите" << endl;
	cout << "1. Создать и записать" << endl;
	cout << "2. Считать" << endl;
	cout << "3. Сортировать" << endl;
	cout << "4. Индивидуалка" << endl;
	cout << "5. Удаление" << endl;
	cout << "6. Редактирование" << endl;
	cout << "7. Завершение работы" << endl;
	cin >> choise; 
	switch (choise) {
	
	case 1:  filefill();  break;
	case 2:  fileread();  break;
	case 3:  fsort(); break;
	case 4:  filetask(); break;
	case 5:  filedel(); break;
	case 6:  update(); break;
	case 7: return 0; break;
	default: cout << "Выберите функцию из предложенных" << endl;
	}
	}
	return 0;
}
void filefill() {
	char path[70];
	cout << "Введите путь" << endl;
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
	} while (v != '2');
	fclose(my_file);
}


void fileread() {
	char path[70];
	cout << "Введите путь" << endl;
	cin >> path;
	FILE* my_file;
	fopen_s(&my_file, path, "rb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	int n = _filelength(_fileno(my_file)) / sizeof(stud);

		for (int i = 0; i < n; i++) {
			stud student;
			fread(&student, sizeof(stud), 1, my_file);
			cout << "Студент номер " << i + 1 << endl;
			cout << "Фамилия: " << student.surname << endl;
			cout << "Номер группы: " << student.num << endl;
			cout << "Оценка по физике: " << student.fiz << endl;
			cout << "Оценка по матеше: " << student.mat << endl;
			cout << "Оценка по инфе: " << student.inf << endl;
		}

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
				if (student[i].srball < student[j].srball)
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

void filedel() {
	char path[70];
	cout << "Введите путь" << endl;
	cin >> path;
	FILE* my_file;
	fopen_s(&my_file, path, "rb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	int f;
	cout << "Кого щелкнул Танос?" << endl;
	cin >> f;
	int n = _filelength(_fileno(my_file)) / sizeof(stud);
	for (int i = f; i < n; i++)
	{
		stud student;
		fseek(my_file,  (i + 1) * sizeof(stud), 0);
		fread(&student, sizeof(stud), 1, my_file);
		fseek(my_file, i * sizeof(stud), 0);
		fwrite(&student, sizeof(stud), 1, my_file);
	}

	f = _chsize(_fileno(my_file), (f - 1) * sizeof(stud));
	fclose(my_file);
	cout << endl << "Студент отчислен" << endl;
}

void update() {
	char path[70];
	cout << "Введите путь" << endl;
	cin >> path;
	FILE* my_file;
	stud student;
	fopen_s(&my_file, path, "rb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	int number, choise;
	cout << "Изменить инфу о каком студенте?" << endl;
	do {
		cin >> number;
	} while (number < 0 || number >  _filelength(_fileno(my_file)) / sizeof(stud));
	cout << "Какую?(1 фамилия, 2 группа, 3 оценка по физике, 4 оценка по матеше, 5 оценка по инфе)" << endl;
	cin >> choise;

	fseek(my_file, (number - 1) * sizeof(stud), SEEK_SET);
	fread(&student, sizeof(stud), 1, my_file);
	switch (choise) {
	default: cout << "Выберите одну из предложенный операций" << endl;
	case 1: cin >> student.surname;
		break;
	case 2: cin >> student.num;
		break;
	case 3: cin >> student.fiz;
		break;
	case 4: cin >> student.mat;
		break;
	case 5: cin >> student.inf;
		break;
	}
	student.srball = (student.fiz + student.mat + student.inf) / 3.;
	fseek(my_file, (number - 1) * sizeof(stud), SEEK_SET);
	fwrite(&student, sizeof(stud), 1, my_file);
	fclose(my_file);
}
