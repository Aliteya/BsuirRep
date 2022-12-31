#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <io.h>
#include <regex>

using namespace std;

struct equipment {
	char name[15], marker[15], data[11], readiness[15];
};

void filecreate(char&, FILE*);
void fileread(char&, FILE*);
void filefill(char&, FILE*);
void fileseek(char&, FILE*, int);
void linesearch(char&, FILE*, equipment*, int);
void binsearch(char&, FILE*, equipment*, int, int);
void filesort(char&, FILE*, int&);
void basicsort(char&, FILE*, equipment*, int);
//void quicksort(char&, FILE*, equipment*, int);

int main()
{

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char path[70];
	cout << "Введите путь к текст. файлу" << endl;
	cin >> path;
	FILE* my_file = NULL;

	int flag = 0;

	int choise;
	bool opr = 1;
	while (opr) {
		cout << "Выберите" << endl;
		cout << "1.(файл и без этого создается) Создать" << endl;
		cout << "2. Считать" << endl;
		cout << "3. Записать" << endl;
		cout << "4. Поиск" << endl;
		cout << "5. Сортировать" << endl;
		cout << "6. Остановить программу" << endl;
		cin >> choise;
		switch (choise) {

		case 1:  filecreate(*path, my_file);  break;
		case 2:  fileread(*path, my_file);  break;
		case 3:  filefill(*path, my_file); break;
		case 4:  fileseek(*path, my_file, flag); break;
		case 5:  filesort(*path, my_file, flag); break;
		case 6: return 0; break;
		default: cout << "Выберите функцию из предложенных" << endl;
		}
	}
	return 0;
}
void filecreate(char& path, FILE* my_file) {

	fopen_s(&my_file, &path, "wb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	fclose(my_file);
}
void fileread(char& path, FILE* my_file) {

	fopen_s(&my_file, &path, "rb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	int n = _filelength(_fileno(my_file)) / sizeof(equipment);

	for (int i = 0; i < n; i++) {
		equipment repair;
		fread(&repair, sizeof(equipment), 1, my_file);
		cout << "номер заказа: " << i + 1 << endl;
		cout << "Название: " << repair.name << endl;
		cout << "Марка: " << repair.marker << endl;
		cout << "Дата: " << repair.data << endl;
		cout << "Готовность: " << repair.readiness << endl;
	}

	fclose(my_file);
}

void filefill(char& path, FILE* my_file) {

	equipment repair;
	fopen_s(&my_file, &path, "wb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}
	regex checkdata("((19|20)\\d\\d)\\.(0?[1-9]|1[012])\\.(0?[1-9]|[12][0-9]|3[01])");
	char v;
	do {
		cout << "Введите название" << endl;
		cin >> repair.name;
		cout << "Введите марку" << endl;
		cin >> repair.marker;
		do {
			cout << "Введите дату в формате гггг.мм.дд" << endl;
			cin >> repair.data;
		} while (regex_match(repair.data, checkdata) == false);
		cout << "Введите готовность заказа( <<да>>, если выполнен, <<нет>>, если не выполнен)" << endl;
		cin >> repair.readiness;

		fwrite(&repair, sizeof(equipment), 1, my_file);
		cout << "Введите 1, чтобы продолжить, 2 - чтобы остановить";
		cin >> v;
	} while (v != '2');
	fclose(my_file);
}
void fileseek(char& path, FILE* my_file, int flag) {
	fopen_s(&my_file, &path, "rb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}

	int n = _filelength(_fileno(my_file)) / sizeof(equipment);
	equipment* repair = new equipment[n];
	fread(repair, sizeof(equipment), n, my_file);
	int choise;
	cout << "Выберите поиск: 1 - линейный,  2(ловит только 1 вхождение) - бинарный(сначала отсортируйте)" << endl;
	cin >> choise;
	switch (choise) {
	case 1: linesearch(path, my_file, repair, n);
	case 2: binsearch(path, my_file, repair, n, flag);
	}
	delete[] repair;
	fclose(my_file);
}
void linesearch(char& path, FILE* my_file, equipment* repair, int n) {
	char data1[11];
	regex checkdata("((19|20)\\d\\d)\\.(0?[1-9]|1[012])\\.(0?[1-9]|[12][0-9]|3[01])");
	cout << "Введите дату(гггг.мм.дд) которую хотите найти" << endl;
	do {
		cin >> data1;
	} while (regex_match(data1, checkdata) == false);
	for (int i = 0; i < n; i++)
		if (strcmp(repair[i].data, data1) == 0) {
			cout << "Название: " << repair[i].name << endl;
			cout << "Марка: " << repair[i].marker << endl;
			cout << "Дата: " << repair[i].data << endl;
			cout << "Готовность: " << repair[i].readiness << endl;
		}

}
void binsearch(char& path, FILE* my_file, equipment* repair, int n, int flag) {
	
	if (flag == 1) {
		int low = 0, high = n - 1, mid = 0;
		char data1[11];
		cout << "Введите дату которую хотите найти" << endl;
		cin >> data1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (strcmp(repair[mid].data, data1) == 0) {
				cout << "Название: " << repair[mid].name << endl;
				cout << "Марка: " << repair[mid].marker << endl;
				cout << "Дата: " << repair[mid].data << endl;
				cout << "Готовность: " << repair[mid].readiness << endl;
				break;
			}
			else if (strcmp(repair[mid].data, data1) > 0)
				high = mid - 1;
			else  if (strcmp(repair[mid].data, data1) < 0) 
				low = mid + 1;
		}
	}
	else cout << "Сначала отсортируйте :^D";
}
void filesort(char& path, FILE* my_file, int& flag) {
	fopen_s(&my_file, &path, "rb+");
	if (!my_file) {
		cout << "еррор" << endl;
		return;
	}

	int n = _filelength(_fileno(my_file)) / sizeof(equipment);
	equipment* repair2 = new equipment[n];
	fread(repair2, sizeof(equipment), n, my_file);
	int choise;
	flag = 1;
	cout << "Выберите сортировку: 1 - пузырек, 2 - быстрая сортировка " << endl;
	cin >> choise;
	switch (choise) {
	case 1: basicsort(path, my_file, repair2, n);
		//case 2: quicksort(path, my_file, repair2, n);

	}
	fclose(my_file);
	fopen_s(&my_file, &path, "wb+");
	for (int i = 0; i < n; i++)
		fwrite(&repair2[i], sizeof(equipment), 1, my_file);
	delete[] repair2;
	fclose(my_file);
}
void basicsort(char& path, FILE* my_file, equipment* repair2, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (strcmp(repair2[i].data, repair2[i + 1].data) == true)
			swap(repair2[i].data, repair2[i + 1].data);
	}
	for (int i = 0; i < n; i++) {
		cout << "Название: " << repair2[i].name << endl;
		cout << "Марка: " << repair2[i].marker << endl;
		cout << "Дата: " << repair2[i].data << endl;
		cout << "Готовность: " << repair2[i].readiness << endl;
	}
}