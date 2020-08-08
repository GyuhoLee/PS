#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		int num = (str[4] - '0') * 1000 + (str[5] - '0') * 100 + (str[6] - '0') * 10 + (str[7] - '0');
		int num2 = 26 * 26 * (str[0] - 'A') + 26 * (str[1] - 'A') + (str[2] - 'A');
		if (abs(num - num2) <= 100) cout << "nice\n";
		else cout << "not nice\n";
	}

	return 0;
}