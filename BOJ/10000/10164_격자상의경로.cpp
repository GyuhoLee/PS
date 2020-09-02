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

int N, M, K, y = 0, x = 0;
int dp[16][16];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(dp, 0);
	CIN3(N, M, K);
	if (K)
	{
		x = (K - 1) % M + 1;
		y = (K - 1) / M + 1;
	}
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
		{
			if (i == 1)
			{
				if (j == 1) dp[i][j] = 1;
				else if (i < y && j > x) dp[i][j] = 0;
				else dp[i][j] = dp[i][j - 1];
			}
			else
			{
				if (i > y && j < x) dp[i][j] = 0;
				else if (i > y && j == x) dp[i][j] = dp[i - 1][j];
				else if (i < y && j > x) dp[i][j] = 0;
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	COUT(dp[N][M]);

	return 0;
}