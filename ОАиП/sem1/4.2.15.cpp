
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(0));
	int n, k; 
    

	do {
		cout << "Введите количество элементов (0 < n < 21)";
		cin >> n;
		while (cin.get() != '\n' && cin.get() != ' ' || !cin) {
			cout << "Выйди и зайди нормально." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> n;
		}
	} while (n < 0 || n > 20);

	vector <int> a(n);

	do {
		cout << "Введите 1 для наполнения случайными числами, 2 - ручной ввод";
		cin >> k;
		while (cin.get() != '\n' && cin.get() != ' ' || !cin) {
			cout << "Выйди и зайди нормально." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> k;
		}
	} while (k != 1 && k != 2);

	// считывание
	
	switch (k) {

	case 1:
		for (int i = 0; i < n; i++) {
		 a[i] = rand() % 100 - 50;
		 cout << a[i] << "\t";
	    } 
		for (int i = 0; i < n; i++) {

			if (a[i] % 2 == 0) {
				for (int j = i + 1; j < n; j++) {
					a[j - 1] = a[j];
				}
				i--;
				n--;
			}
		}
			break;

	case 2: 
		for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (cin.get() != '\n' && cin.get() != ' ' || !cin) {
			cout << "Выйди и зайди нормально." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> a[i];
		}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				for (int j = i + 1; j < n; j++) {
					a[j - 1] = a[j];
				}
				i--;
				n--;
			}
		}
			break;

	}
	cout << endl;
	
			for (int i = 0; i < n; i++) {
					cout << a[i] << "\t";
			}

			return 0;
	}
