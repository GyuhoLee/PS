#include <iostream>
#include <string>
using namespace std;

int N, ans = 0;
string str;

int main()
{
	cin >> N;
	while (N--)
	{
		ans = 0;
		cin >> str;
		for (int i = 0; i < 16; i++)
		{
			int num = str[i] - '0';
			if (i % 2) ans += num;
			else if (num < 5) ans += (num * 2);
			else ans += ((num - 5) * 2 + 1);
		}
		if (ans % 10) cout << "F\n";
		else cout << "T\n";
	}

	return 0;
}