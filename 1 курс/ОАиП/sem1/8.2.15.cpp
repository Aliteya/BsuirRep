#include<iostream>
#include<cmath>

using namespace std;

void Out_Rez(double e){
    cout << e << '\n';
}
void efind(double s, double y, double& e) {
   e = abs(s - y);
}
int main()
{
    int i = 0;
    double y, a, b, h, e;
    cin >> a >> b >> h;
    for (double x = a; x <= b; x += h, i++)
    {
        double k = 1, s = 0, r = 1;
        y = x * atan(x) - log(sqrt(1 + x * x));
        do
        {
            r *= -1 * x * x;
            s += r * -1 / (2 * k * (2 * k - 1));
            efind(s, y, e);
            Out_Rez(e);
            k++;
        } while (e >= 0.1);
    }
    cout << "\n" << i;
    return 0;
}
