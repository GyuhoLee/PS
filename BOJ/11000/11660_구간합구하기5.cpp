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

ll N, M, arr[1025][1025], sum[1025][1025];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 1, N)
	{
		sum[i][0] = 0;
		FUP(j, 1, N)
		{
			CIN(arr[i][j]);
			sum[i][j] = sum[i][j - 1] + arr[i][j];
		}
	}
	while (M--)
	{
		ll ans = 0, a, b, c, d;
		CIN2(a, b);
		CIN2(c, d);
		FUP(i, a, c)
		{
			ans += (sum[i][d] - sum[i][b - 1]);
		}
		COUT(ans);
		ENDL;

	}

	return 0;
}