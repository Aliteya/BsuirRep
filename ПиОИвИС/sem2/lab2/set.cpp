#include <iostream>
#include "set.h"
#include <string>

void test1();
void test2();
void test3();
void test4();
void test5();

int main(){
std:: cout << "Test 1:" << std :: endl;
  test1();
std:: cout << std:: endl;
std:: cout << "Test 2:" << std :: endl;
   test2();
std:: cout << std:: endl;
std:: cout << "Test 3:" << std :: endl;
    test3();
std:: cout << std:: endl;
std:: cout << "Test 4:" << std :: endl;
    test4();
std:: cout << std:: endl;
std:: cout << "Test 5:" << std :: endl;
    test5();

return 0;
}


void test1(){
    set<int> se1(0);
  std :: cout << "Set 1: "<< std :: endl;  
    se1.print();
  std :: cout << std :: endl;
    set<int> se2(0); 
  std :: cout << "Set 2: "<< std :: endl;      
    se2.print();
  std :: cout << std :: endl;
  std :: cout << "Union: "<< std :: endl;  
    uni_n(2, se1, se2).print();
    return;
}

void test2(){
     set<int> se1(3);
     se1.push(1);
     se1.push(2);
     se1.push(3);
     std :: cout << "Set 1: "<< std :: endl;  
     se1.print();
  std :: cout << std :: endl;
     set<int> se2(3);
     se2.push(3);
     se2.push(4);
     se2.push(6);
     std :: cout << "Set 2: "<< std :: endl;  
     se2.print();
   std :: cout << std :: endl;  
     set<int> se3(3);
     se3.push(4);
     se3.push(7);
     se3.push(8);
     std :: cout << "Set 3: "<< std :: endl;  
     se3.print();
   std :: cout << std :: endl;
   std :: cout << "Union: "<< std :: endl;  
   uni_n(3, se1, se2, se3).print();
  return;
}

void test3(){
   set<int> se1(3);
     se1.push(1);
     se1.push(1);
     se1.push(3);
     std :: cout << "Set 1: "<< std :: endl;  
     se1.print();
  std :: cout << std :: endl;
     set<int> se2(3);
     se2.push(3);
     se2.push(4);
     se2.push(6);
     std :: cout << "Set 2: "<< std :: endl;  
     se2.print();
   std :: cout << std :: endl;
   std :: cout << "Union: "<< std :: endl;  
   uni_n(2, se1, se2).print();
   return;
}

void test4(){
    set<int> se1(3);
     se1.push(1);
     se1.push(2);
     se1.push(3);
     std :: cout << "Set 1: "<< std :: endl;  
     se1.print();
     std :: cout << "Delete x = 2: "<< std :: endl;  
     se1.pop(2);
     std :: cout << "Set 1 result: "<< std :: endl;  
     se1.print();
     std :: cout << "Delete x = 0: "<< std :: endl;  
     se1.pop(0);
    return;
}

void test5(){
  set<std :: string> res(3);
  res.push("<1 2>");
  res.push("<3 4>");
  res.push("<4 5>");
  res.print();
  return;
}
