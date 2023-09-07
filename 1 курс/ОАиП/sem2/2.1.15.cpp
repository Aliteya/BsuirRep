#include <iostream>
using namespace std;

double rec(int& n) {
    double y = 0;
    if (n == 0)
        return y;
    else {
        n--;
        y = 1. / (1 + rec(n));

    }
}
int main()
{
    int n;
    cin >> n;
    cout << rec(n);
}
