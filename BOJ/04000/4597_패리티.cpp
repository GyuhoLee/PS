#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		string str;
		cin >> str;
		if (str == "#") break;
		int one = 0;
		for (auto s : str)
		{
			if (s == '1') one++;
			else if (s == 'e')
			{
				if (one % 2 == 0) str[str.length() - 1] = '0';
				else str[str.length() - 1] = '1';
			}
			else if (s == 'o')
			{
				if (one % 2) str[str.length() - 1] = '0';
				else str[str.length() - 1] = '1';
			}
		}
		cout << str << '\n';
	}
	

	return 0;
}