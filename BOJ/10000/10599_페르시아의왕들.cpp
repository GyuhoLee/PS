#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	while (true)
	{
		cin >> a >> b >> c >> d;
		if (!a && !d) break;
		cout << c - b << ' ' << d - a << '\n';
	}

	return 0;
}