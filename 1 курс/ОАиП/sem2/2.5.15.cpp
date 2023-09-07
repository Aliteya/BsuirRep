#include<iostream>
#include<string>

struct sta{
    char info;
    sta* next = NULL;
};

sta* pop(sta* root)
{
	sta* t = NULL;
	if (root != NULL) t = root->next;
	delete root;
	return t;
}

void in(sta** root, char _info){
    sta* curr;
    curr = new sta();
    curr->info = _info;
    if (*root == NULL){
        *root = curr;
    }
    else{
        curr->next = *root;
        *root = curr;
    }

}

sta* out(sta* root, char* _info){
    sta* curr = root;
    *_info = root->info;
    root = root->next;
    delete curr;
    return root;
}

void deleteAll(sta* root)
{
	while (root != NULL) {
		sta* t = root;
		root = root->next;
		delete t;
	}
}

int prior(char _inf){
switch(_inf){
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(': 
        return 1;
}
return 0;
}

void translate(std :: string instr){
sta* root = NULL;
char inf, a;

std :: string outstr="";

for(int i=0; i < instr.length(); i++){
    inf = instr[i];

    if(inf == '('){
        in(&root, inf);
    }

    else if(inf == ')'){
        while((root->info) != '('){
            root = out(root, &a);
            outstr += a;
        }
        root = out(root, &a);
    }

    else if(inf >= 'a' && inf <= 'z'){
        outstr += inf;
    }

    else if(prior(inf) != 0 && prior(inf) != 1){
        while(root!= NULL && prior(root->info) >= prior(inf)){
            root = out(root, &a);
            outstr += a;
        }
        in(&root, inf);
    }
}
while(root != NULL){
        root = out(root, &a);
        outstr +=a;
    }
std :: cout << outstr;
}

void calc(std :: string instr){
    sta* root = NULL;
    char inf;
    int res;
    for (int i = 0; i < instr.length(); i++){
        inf = instr[i];
        if (inf >= '0' && inf <= '9'){
            in(&root, inf - '0');
        }
        else{
            int oper1, oper2;
            oper2 = root->info;
            root = pop(root);
            oper1 = root->info;
            root = pop(root);
            switch (inf)
            {
            case '+': in(&root, oper1 + oper2); break;
            case '-': in(&root, oper1 - oper2); break;
            case '*': in(&root, oper1 * oper2); break;
            case '/': in(&root, oper1 / oper2); break;
            }
        }
    }
    if (root == NULL){
        res = 0;
    }
    else{
        res = root->info;
    }
    deleteAll(root);
    std :: cout << res;
}

int main(){
std :: string instr="(a+b*c)/(d-e)";
std :: string outstr="123*+54-/";

translate(instr);
std :: cout << std:: endl;
std :: cout << "123*+54-/" << std :: endl;
calc(outstr);

return 0;
}