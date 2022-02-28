#include <iostream>
#include <cmath>
using namespace std;

double a, b, c, d, s;
double m(double n)
{
	return s - n;
}

int main()
{
	cin >> a >> b >> c >> d;
	s = (a + b + c + d) / 2;
	cout.precision(10);
	cout << sqrt(m(a) * m(b) * m(c) * m(d));

	return 0;
}