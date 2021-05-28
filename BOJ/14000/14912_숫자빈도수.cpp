#include <iostream>
#include <string>
using namespace std;

int n, d, ans = 0;

int main()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		string str = to_string(i);
		for (char ch : str)
		{
			ans += (ch == d + '0');
		}
	}
	cout << ans;

	return 0;
}