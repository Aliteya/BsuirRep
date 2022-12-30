
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int i = 0;
	double y, a, b, h, e;
	cin >> a >> b >> h;
	for (double x = a; x <= b; x += h, i++) {
		y = x * atan(x) - log(sqrt(1 + pow(x, 2)));
		double k = 1, s = 0;
		do
		{
			s += pow(-1, k + 1) * pow(x, 2 * k) / (2 * k * (2 * k - 1));
			e = abs(s - y);
			cout << e << endl;
			k++;
		} while (e >= 0.001);
	}
	 cout << i;
	return 0;
}
