#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	for (auto s : str)
	{
		s -= 3;
		if (s < 'A') s += 26;
		cout << s;
	}

	return 0;
}