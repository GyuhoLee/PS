#include <iostream>
using namespace std;

int a, b, c, A, B, C, x;

int main()
{
	cin >> a >> b >> c >> A >> B >> C;
	x = A - a;
	if (B < b) x--;
	else if (B == b && C < c) x--;
	cout << x << '\n' << A - a + 1 << '\n' << A - a;

	return 0;
}