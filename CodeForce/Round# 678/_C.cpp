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
#define MOD 1000000007
ll N, X, pos;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, X, pos);
	ll total = N - 1, big = N - X, small = X - 1;
	ll left = 0, right = N;
	ll ans = 1;
	while (left < right)
	{
		ll mid = (left + right) / 2;
		if (mid > pos)
		{
			if (big == 0)
			{
				ans = 0;
				break;
			}
			right = mid;
			ans *= big;
			ans %= MOD;
			big--;
			total--;
		}
		else if (mid < pos)
		{
			if (small == 0)
			{
				ans = 0;
				break;
			}
			left = mid + 1;
			ans *= small;
			ans %= MOD;
			small--;
			total--;
		}
		else
		{
			left = mid + 1;
		}
	}
	FUP(i, 2, total)
	{
		ans *= i;
		ans %= MOD;
	}
	COUT(ans);

	return 0;
}