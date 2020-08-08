#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main ()
{
    int a, b;
    char c;
    cin >> a >> c >> b;
    int d = gcd(a, b);
    cout << a / d << c << b / d;
}