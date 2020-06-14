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

	int T;
	cin >> T;
	while (T--)
	{
		ll answer = 0;
		ll x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll x = x2 - x1;
		ll y = y2 - y1;
		if (x < y) swap(x, y); // 작은것은 y이다
		ll sum = x * (x - 1);
		sum += ((x + y - 1 - 2 * (x - 1)) * x);
		cout << sum + 1 << '\n';
	}

	return 0;
}