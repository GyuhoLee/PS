#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a = 10000000;
	int b = -10000000;
	int N;
    cin >> N;
	while (N--)
	{
		int num;
		cin >> num;
		a = min(num, a);
		b = max(num, b);
	}
	cout << a << " " << b;

	return 0;
}
