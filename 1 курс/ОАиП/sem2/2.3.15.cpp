#include <iostream>

using namespace std;

struct StackNode {
	int val;
	StackNode* next;
};

StackNode* newNode(int _val) {
	StackNode* newnode = new StackNode();
	newnode->val = _val;
	newnode->next = nullptr;
	return newnode;	
}

int isEmpty(StackNode* root) {
	return !root;
}

void push(StackNode** root, int new_val) {
	StackNode* new_node = newNode(new_val);
	
	new_node->next = *root;
	*root = new_node; 
}

void sort(StackNode* root) {
	StackNode* temp = nullptr, *temp1;
	if (isEmpty(root)) {
		cout << "Стек пуст";
		return;
	}
	else {
		do {
			for (temp1 = root;temp1->next != temp; temp1 = temp1->next) {
				if (temp1->val > temp1->next->val) {
					swap(temp1->val, temp1->next->val);
				}
			}
			temp = temp1;
		} while (root->next != temp);
	}
}

void print(StackNode* root) {
	StackNode* curr;
	curr = root;
	while (curr != nullptr) {
		cout << curr->val<< endl;
		curr = curr->next;
	}
	
}
void task(StackNode** root)
{
	StackNode* t;
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
			StackNode* l = t->next;
			t->next = t->next->next;
			delete l;
		}
		else t = t->next;
	}
}

void clear(StackNode** root) {
	if (isEmpty(*root)) {
		cout << "Стек пуст";
		return;
	}
	StackNode* t;
	while((*root) != nullptr) {
		t = *root;
		*root = (*root)->next;
		delete t;
	}
}

int main() {
	StackNode* root = nullptr;
	
	push(&root, 1);
	push(&root, 2);
	push(&root, 3);
	push(&root, 8);
	push(&root, 5);
	print(root);
	cout<<"---------------------" << endl;
	sort(root);
	print(root);
	cout << "---------------------" << endl;
	task(&root);
	print(root);
	clear(&root);
	return 0;
}