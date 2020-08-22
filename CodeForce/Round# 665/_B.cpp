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

int T, a[3], b[3], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		ans = 0;
		CIN3(a[0], a[1], a[2]);
		CIN3(b[0], b[1], b[2]);
		if (a[2] >= b[1])
		{
			a[2] -= b[1];
			ans += (b[1] * 2);
			b[1] = 0;
			if (a[2] >= b[2])
			{
				a[2] -= b[2];
				b[2] = 0;
				b[0] -= a[2];
				a[2] = 0;
			}
			else
			{
				b[2] -= a[2];
				a[2] = 0;
			}
		}
		else
		{
			ans += (a[2] * 2);
			b[1] -= a[2];
		}
		if (b[2] > a[0])
		{
			b[2] -= a[0];
			ans -= (b[2] * 2);
		}
		
		COUT(ans);
		ENDL;
		

	}

	return 0;
}