#include <iostream>
using namespace std;

void fun(int*, int, double&, bool&);

int main()
{
    int N;
    bool s = true;
    double k = 0;
    cin >> N;
    int* A = new int[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
        cout << A[i]<< " ";
    cout << endl;
    fun(A, N, k, s);
    for (int i = 0; i < N; i++) 
        cout << A[i] << " ";
    cout << endl;
    if (s == false)
        cout << k;

    return 0;
}
void fun(int* A, int N, double& k, bool& s) {
    int y = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > 0) {
            k += A[i];
            y++;
            s = false;
          
        }
        else if (A[i] < 0)
            A[i] *= 2;
    }
    k /= y;
}