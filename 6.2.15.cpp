
#include <cstring>
#include <iostream> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    char a[200];
    int lenw = 0, num = 1;


    cin.getline(a, 200);

    int minlen = strlen(a);

    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != ' ' && a[i] != '\0') {
            lenw++;
        }
        else num++;

        if (lenw) {
            if (lenw < minlen) {
                minlen = lenw;
            }

            lenw = 0;
        }

    }
    std::cout << num << "\t" << minlen;

    return 0;
}