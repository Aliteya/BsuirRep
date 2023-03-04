#include <iostream>

using namespace std;

struct que {
	int val;
	que* next;
	que* prev;
};

//void newNode(que **root,que **end ,int _val) {
//	curr = new que;
//	curr->val = _val;
//	curr->next = curr->prev = nullptr;
//	*root = *end = curr;
//}

void push_back(que** root, int new_val) {
	que* curr = new que;
	que* end = *root;

	curr->val = new_val;
	curr->next = nullptr;
	if ((*root) == nullptr) {
		curr->prev = nullptr;
		(*root) = curr;
		return;
	}
	while (end->next != nullptr) {
		end = end->next;
	}

	end->next = curr;
	curr->prev = end;
	return;
}

void push_front(que** root, int new_val) {
	que *curr = new que;

	curr->val = new_val;

	curr->next = (*root);
	curr->prev = nullptr;
	
	if ((*root) != nullptr)
	(*root)->prev = curr;	
	(*root) = curr;
}

void print(que* curr) {
	que* end;
	while (curr != nullptr) {
		cout << curr->val << endl;
		end = curr;
		curr = curr->next;
	}
	if (curr == nullptr) {
		cout << "null :(";
	}
}

void task(que** root)
{
	que* t;
	while ((*root)->val % 2 != 0)
	{
		t = *root;
		*root = (*root)->next;
		delete t;
	}
	t = *root;
	while (t->next != nullptr)
	{
		if (t->next->val % 2 != 0)
		{
			que* l = t->next;
			t->next = t->next->next;
			delete l;
		}
		else t = t->next;
	}
}

void clear(que** root) {
	que* t;
	while ((*root) != nullptr) {
		t = *root;
		*root = (*root)->next;
		delete t;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	que* root = nullptr;
	push_back(&root, 1);
	push_back(&root, 2);
	push_front(&root, 3);
	task(&root);
	print(root);
	clear(&root);
	return 0;
}
