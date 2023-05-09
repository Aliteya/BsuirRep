#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tree_node{
    int key;
    string name;
    tree_node *left = NULL;
    tree_node *right = NULL;
}*root;

void insert(int _key, string _name){
    tree_node *curr = root;
    if(!curr){
        curr = new tree_node();
        curr->key = _key;
        curr->name = _name;
        root = curr;
    }
    while(curr && curr->key != _key){
        if (curr->key > _key && curr ->left == NULL){
            curr->left = new tree_node();
            curr->left->key = _key;
            curr->left->name = _name;
            return;
        }
        if (curr->key < _key && curr-> right == NULL){
            curr->right = new tree_node();
            curr->right->key = _key;
            curr->right->name = _name;
            return;
        }
        if(curr->key > _key){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

void find(int _key){
    tree_node * curr = root;
    while(curr && curr->key != _key){
        if(curr->key > _key){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    if(!curr){
        cout << "error not found"<<endl;
        return;
    }
    else{
       cout << curr->key << " "<< curr->name <<endl;
       return; 
    }

}

void erase(int _key, string _name){
    tree_node *curr = root;
    tree_node *prev = NULL;
    
    while(curr && curr->key != _key) {
        prev = curr;
        if(curr->key > _key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(!curr)
        return;

    if (curr->left == NULL && curr->right == NULL){
        delete curr;
        if(prev && prev->left == curr) 
            prev->left = NULL; 
        else if(prev && prev->right == curr) 
            prev->right = NULL;    
        else 
            root = NULL; // если удаляем корень
        return; 
    }

    if (curr->left == NULL){
        if(prev && prev->left == curr)
            prev->left = curr->right;
        else if(prev && prev->right == curr)
            prev->right = curr->right;
        else // если удаляем корень
            root = curr->right;
        delete curr;   
        return;
    }
    if(curr->right == NULL){
        if(prev && prev->left == curr)
            prev->left = curr->left;
        else if(prev && prev->right == curr)
            prev->right = curr->left;
        else // если удаляем корень
            root = curr->left;
        delete curr;
        return;
    }
    tree_node *replace = curr->right;
    while(replace->left)
        replace = replace->left;
    int repl_key = replace->key;
    string repl_name = replace->name;
    erase(repl_key, repl_name);
    curr->key = repl_key;
    curr->name = repl_name;

}

void bal(tree_node **p, int n, int k, vector<pair<int, string>> a ){
    if(n == k){
        (*p) = NULL;
    }
    else{
        int m = (n + k) / 2;
        (*p) = new tree_node;
        (*p)->key = a[m].first;
        (*p)->name = a[m].second;
        bal(&((*p)->left), n, m, a);
        bal(&((*p)->right), m + 1, k , a);
    }
}

void show_prefix(tree_node *root){
   if(root != NULL){
    cout << root->name << " ";
    show_prefix(root->left);
    show_prefix(root->right);
   }
}

void show_interfix(tree_node *root){
   if(root != NULL){
    show_interfix(root->left);
    cout << root->name << " ";
    show_interfix(root->right);
   }
}

void show_postfix(tree_node *root){
   if(root != NULL){
    show_postfix(root->left);
    show_postfix(root->right);
    cout << root->name << " ";
   }
}

void clear(tree_node *root){
    if(root != NULL){
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

int main(){
    vector<pair<int, string>> data = {  {8, "right3"},  {2, "left"}, {4, "second"}, {9, "right"},  {7, "right2"}, {10, "right4"}};

   tree_node *p = NULL;
   bal(&p, 0, data.size(), data);
   cout << endl;
   show_prefix(p);
   clear(p);
 cout << endl;
     insert(4, "second");
     insert(2, "left");
     insert(9, "right");
     show_interfix(root);
     find(9);
     clear(root);
    return 0;
}