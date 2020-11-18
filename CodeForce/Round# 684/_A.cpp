#include <bits/stdc++.h>
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

int T, n, c0, c1, h;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	CIN(T);
	while (T--)
	{
		CIN2(n, c0);
		CIN3(c1, h, s);
		int zero = 0, one = 0;
		for (char ch : s)
		{
			if (ch == '0') zero++;
			else one++;
		}
		int ans = one * c1 + zero * c0;
		ans = min(ans, c1 * n + h * zero);
		ans = min(ans, c0 * n + h * one);
		COUT(ans);
		ENDL;
	}

	return 0;
}