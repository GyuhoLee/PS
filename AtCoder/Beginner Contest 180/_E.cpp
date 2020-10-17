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

int N;
ll ans = -1;
ll d[17][1 << 17];
struct Point
{
	ll x, y, z;
	Point(ll xx, ll yy, ll zz) : x(xx), y(yy), z(zz) {}
	Point() {}
};
Point arr[17];

ll dist(Point i, Point j)
{
	ll ret = abs(i.x - j.x) + abs(i.y - j.y);
	if (j.z > i.z) ret += (j.z - i.z);
	return ret;
}

void dp(int before, int bit, ll num)
{
	if (bit + 1 == 1 << N)
	{
		if (ans == -1) ans = num + dist(arr[before], arr[0]);
		else ans = min(ans, num + dist(arr[before], arr[0]));
		return;
	}
	FUP(i, 1, N - 1)
	{
		if ((bit & (1 << i)) == 0)
		{
			ll tmp = num + dist(arr[before], arr[i]);
			int next = bit | (1 << i);
			if (d[i][next] != -1 && d[i][next] <= tmp) continue;
			d[i][next] = tmp;
			dp(i, next, tmp);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(d, -1);
	CIN(N);
	FUP(i, 0, N - 1)
	{
		CIN3(arr[i].x, arr[i].y, arr[i].z);
	}
	dp(0, 1, 0);
	COUT(ans);


	return 0;
}