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
#define CIN4(a, b, c, d) cin >> a >> b >> c >> d
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll x = 0, y = 0, x1, x2, y1, y2, x11, x22, y11, y22;
	CIN4(x1, y2, x2, y1);
	CIN4(x11, y22, x22, y11);
	if (x1 > x11)
	{
		swap(x1, x11);
		swap(x2, x22);
	}
	if (x2 > x11)
	{
		x = min(x2, x22) - x11;
	}
	if (y1 > y11)
	{
		swap(y1, y11);
		swap(y2, y22);
	}
	if (y2 > y11)
	{
		y = min(y2, y22) - y11;
	}
	COUT(x * y);

	return 0;
}