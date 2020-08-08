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

	string str;
	getline(cin, str);
	for (auto s : str)
	{
		if (s >= 'a' && s <= 'z')
		{
			if(s + 13 > 'z') s -= 13;
			else s += 13;
			cout << s;
		}
		else if(s >= 'A' && s <= 'Z')
		{
			s += 13;
			if (s > 'Z') s -= 26;
			cout << s;
		}
		else cout << s;
	}

	return 0;
}