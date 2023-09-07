#pragma once

#include <iostream>
#include <vector>

//#define DEBUG

using namespace std;

// класс узлов дерева
class Node {
public:
	// элементы дерева
	int val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node* construct(vector <vector <int>>& grid, int n, vector<pair<int, bool>>& res);
	vector<vector<int>> toMatrix(Node* root, int n);
private:
	bool is_val_same(vector <vector <int>>& grid, int x, int y, int n);
	Node* create(vector <vector <int>>& grid, int x, int y, int n, vector<pair<int, bool>>& res);
	void quadTreeToMatrixHelper(Node* node, int x, int y, int rowEnd, int colEnd, vector<vector<int>>& mat);
	// конструктор класса по умолчанию
public:
	Node() {
#ifdef	DEBUG
		cout << "я в конструкторе" << endl;
#endif		
		val = -1;
		isLeaf = 0;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}
	// конструктор для листа дерева без потомков
	Node(int _val, bool _isLeaf) {
#ifdef	DEBUG
		cout << "я узел - листочек" << endl;
#endif	
		val = _val;
		isLeaf = _isLeaf;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;

	}
	//для корня с потомками
	Node(int _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
#ifdef	DEBUG		
		cout << "я конструктор корня" << endl;
#endif	
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};