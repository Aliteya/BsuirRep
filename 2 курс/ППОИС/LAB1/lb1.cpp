#include <conio.h>
#include "real_matrix.h"

int main() {
    real_matrix a("prim.txt");
    a.determine_type();
    std::cout << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    a.change_form(5, 5);
    a.transponse();
    std::cout << a;
    while (_getch() != (const char)13);
    return 0;
}
