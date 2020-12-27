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

ll X, Y, Z, ans = -1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(X, Y);
	Z = Y * 100 / X;
	if (Z >= 99)
	{
		COUT(-1);
		return 0;
	}
	ll l = 0, r = 2000000000, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if ((Y + mid) * 100 / (X + mid) > Z)
		{
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	COUT(ans);

	return 0;
}