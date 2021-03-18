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

ll gcd(ll x, ll y)
{
	if (x < y) swap(x, y);
	ll rest;
	while (y)
	{
		rest = x % y;
		x = y;
		y = rest;
	}
	return x;
}

ll N, M, ans, g;

ll solve()
{
	CIN2(N, M);
	if (N > M) swap(N, M);
	ll ret = N;
	if (N == 1) return M;
	if (N == M) return N;
	ll p = N - 1, q = M - 1;
	ll g = gcd(p, q);
	p /= g;
	q /= g;
	ll tmp = 2 * g * p - p + 1;
	tmp *= (q - 1);
	tmp /= 2;
	return ret + tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	COUT(solve());

	return 0;
}