#include <iostream>
#include <vector>
#include <cmath>
#include "qua.h"

using namespace std;

bool n_checker(int n);

void test1();

void test2();

void test3();

void test4();

void test5();

int main() {
	setlocale(LC_ALL, "ru");

	test1();
	cout << endl << "-------------------------------------------------------" << endl;
	test2();
	cout << endl << "-------------------------------------------------------" << endl;
	test3();
	cout << endl << "-------------------------------------------------------" << endl;
	test4();
	cout << endl << "-------------------------------------------------------" << endl;
	test5();

	return 0;
}
bool n_checker(int n) {
	float a;
	a = log2(n);
	if (a == round(a)) {
		return true;
	}
	return false;
}

void test1() {

	int n = 2;
	if (n_checker(n) == false) {
		cout << "глубина квадродерева - степень 2";
		return;
	}
	vector <vector <int>> grid = { {1, 0}, {1, 0} };
	cout << "Исходная таблица" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	vector <pair <int, bool>> res;
	Node tree;
	tree.construct(grid, n, res);
	cout << "Дерево <3" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "Value: " << res[i].first << " Is Leaf? " << boolalpha << res[i].second << endl;
	}

	vector<vector<int>> mat = tree.toMatrix(tree.construct(grid, n, res), n);
	cout << "Матрица сформированная из дерева" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void test2() {
	int n = 4;
	if (n_checker(n) == false) {
		cout << "глубина квадродерева - степень 2";
		return;
	}
	vector <vector <int>> grid = { {1, 1, 0, 0},
								   {1, 1, 1, 1},
								   {1, 0, 0, 0},
								   {0, 1, 0, 0} };
	cout << "Исходная таблица" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	vector <pair <int, bool>> res;
	Node tree;

	tree.construct(grid, n, res);
	cout << "Дерево <3" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "Value: " << res[i].first << " Is Leaf? " << boolalpha << res[i].second << endl;
	}

	vector<vector<int>> mat = tree.toMatrix(tree.construct(grid, n, res), n);
	cout << "Матрица сформированная из дерева" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void test3() {
	int n = 2;
	if (n_checker(n) == false) {
		cout << "глубина квадродерева - степень 2";
		return;
	}
	vector <vector <int>> grid = { {1, 1},
								   {1, 1} };
	cout << "Исходная таблица" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	vector <pair <int, bool>> res;
	Node tree;

	tree.construct(grid, n, res);
	cout << "Дерево <3" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "Value: " << res[i].first << " Is Leaf? " << boolalpha << res[i].second << endl;
	}

	vector<vector<int>> mat = tree.toMatrix(tree.construct(grid, n, res), n);
	cout << "Матрица сформированная из дерева" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void test4() {
	int n = 3;
	if (n_checker(n) == false) {
		cout << "глубина квадродерева - степень 2";
		return;
	}
	vector <vector <int>> grid = { {1, 1, 0},
								   {0, 0, 0},
								   {1, 1, 0} };
	cout << "Исходная таблица" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	vector <pair <int, bool>> res;
	Node tree;

	tree.construct(grid, n, res);
	cout << "Дерево <3" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "Value: " << res[i].first << " Is Leaf? " << boolalpha << res[i].second << endl;
	}

	vector<vector<int>> mat = tree.toMatrix(tree.construct(grid, n, res), n);
	cout << "Матрица сформированная из дерева" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void test5() {

	int n = 1;
	if (n_checker(n) == false) {
		cout << "глубина квадродерева - степень 2";
		return;
	}
	vector <vector <int>> grid = { {4} };
	cout << "Исходная таблица" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	vector <pair <int, bool>> res;
	Node tree;
	tree.construct(grid, n, res);
	cout << "Дерево <3" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "Value: " << res[i].first << " Is Leaf? " << boolalpha << res[i].second << endl;
	}

	vector<vector<int>> mat = tree.toMatrix(tree.construct(grid, n, res), n);
	cout << "Матрица сформированная из дерева" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}