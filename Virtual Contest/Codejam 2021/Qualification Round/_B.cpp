#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int T, X, Y;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	regex re("[?]+");
	CIN(T);
	FUP(t, 1, T)
	{
		int ans = 0;
		CIN3(X, Y, str);
		str = regex_replace(str, re, "?");
		int len = str.length();
		FUP(i, 0, len - 2)
		{
			if (str[i] == '?')
			{
				if (i == 0 || str[i - 1] == str[i + 1]) continue;
				else if (str[i - 1] == 'C' && str[i + 1] == 'J') ans += X;
				else ans += Y;
			}
			else if (str[i] == 'C' && str[i + 1] == 'J') ans += X;
			else if (str[i] == 'J' && str[i + 1] == 'C') ans += Y;
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}