#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		string str;
		cin >> str;
		if (str[0] == '0') break;
		if (str.size() == 1)
		{
			cout << "yes\n";
			continue;
		}
		bool ok = true;
		FUP(i, 0, str.size() / 2 - 1)
		{
			if (str[i] != str[str.size() - 1 - i])
			{
				ok = false;
				break;
			}
		}
		if (ok) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}