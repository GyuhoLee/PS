#include <iostream>
using namespace std;
int a, b, n, w;

int main()
{
	cin >> a >> b >> n >> w;
	if (a == b && a * 2 != w)
	{
		cout << -1;
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (i * a + (n - i) * b == w)
		{
			cout << i << ' ' << n - i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}