#include "qua.h"

bool Node::is_val_same(vector <vector <int>>& grid, int x, int y, int n) {
#ifdef	DEBUG	
	cout << "я сравниваю значения в матрице" << endl;
#endif	
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (grid[i][j] != grid[x][y])
				return false;
		}
	}
	return true;
}

Node* Node::create(vector <vector <int>>& grid, int x, int y, int n, vector<pair<int, bool>>& res) {
#ifdef	DEBUG	
	cout << "я создаю дерево" << endl;
#endif	
	if (is_val_same(grid, x, y, n) == true) {
		Node* leaf = new Node(grid[x][y], true);
		res.push_back({ leaf->val, leaf->isLeaf });
		return leaf;
	}
	else {
#ifdef	DEBUG
		cout << "я ветка" << endl;
#endif
		Node* root = new Node(-1, false);

		res.push_back({ root->val, root->isLeaf });

		root->topLeft = create(grid, x, y, n / 2, res);
		root->topRight = create(grid, x, y + n / 2, n / 2, res);
		root->bottomLeft = create(grid, x + n / 2, y, n / 2, res);
		root->bottomRight = create(grid, x + n / 2, y + n / 2, n / 2, res);
		return root;
	}
}

Node* Node::construct(vector <vector <int>>& grid, int n, vector<pair<int, bool>>& res) {
#ifdef	DEBUG
	cout << "я возвращаюсь" << endl;
#endif
	return create(grid, 0, 0, n, res);
}

void Node::quadTreeToMatrixHelper(Node* node, int x, int y, int rowEnd, int colEnd, vector<vector<int>>& mat) {
	if (node == nullptr) {
		return;
	}

	if (node->topLeft == nullptr && node->topRight == nullptr && node->bottomLeft == nullptr && node->bottomRight == nullptr) {
		for (int i = x; i <= rowEnd; i++) {
			mat.push_back(vector<int>());
			for (int j = y; j <= colEnd; j++) {
				mat[i].push_back(node->val);
			}
		}
		return;
	}

	int rowMid = (x + rowEnd) / 2;
	int colMid = (y + colEnd) / 2;


	quadTreeToMatrixHelper(node->topLeft, x, y, rowMid, colMid, mat);
	quadTreeToMatrixHelper(node->topRight, x, colMid + 1, rowMid, colEnd, mat);
	quadTreeToMatrixHelper(node->bottomLeft, rowMid + 1, y, rowEnd, colMid, mat);
	quadTreeToMatrixHelper(node->bottomRight, rowMid + 1, colMid + 1, rowEnd, colEnd, mat);


}

vector<vector<int>> Node::toMatrix(Node* root, int n) {
	vector<vector<int>> mat;
	quadTreeToMatrixHelper(root, 0, 0, n - 1, n - 1, mat);
	return mat;

}