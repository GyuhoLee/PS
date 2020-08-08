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

bool num[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(num, false);
	ll max, min;
	int cnt = 0;
	CIN2(min, max);
	for (ll i = 2; i * i <= max; i++)
	{
		ll i2 = i * i;
		ll x = min / i2;
		if (min % i2 != 0) x++;
		while (x * i2 <= max)
		{
			num[x * i2 - min] = true;
			x++;
		}
	}

	FUP(i, 0, max - min)
	{
		if (!num[i]) cnt++;
	}
	COUT(cnt);

	return 0;
}