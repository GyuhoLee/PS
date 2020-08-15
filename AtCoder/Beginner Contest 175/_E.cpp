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

int R, C, K;
ll arr[3001][3001];
ll dp[3001][3001][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, 0);
	MS(dp, -1);
	CIN3(R, C, K);
	while (K--)
	{
		int a, b, c;
		CIN3(a, b, c);
		arr[a][b] = c;
	}
	FUP(i, 1, R)
	{
		FUP(j, 1, C)
		{
			dp[i][j][0] = 0;
			FDOWN(k, 3, 1)
			{
				if (dp[i][j][k - 1] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + arr[i][j]);
			}
			if (j != 1)
			{
				FDOWN(k, 3, 1)
				{
					if (dp[i][j - 1][k] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
				}
				FDOWN(k, 3, 1)
				{
					if (dp[i][j - 1][k - 1] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + arr[i][j]);
				}
			}
			if (i != 1)
			{
				FDOWN(k, 3, 1) dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][k]);
				dp[i][j][1] = max(dp[i][j][1], dp[i][j][0] + arr[i][j]);
			}
		}
	}
	ll answer = 0;
	FUP(i, 0, 3)
	{
		answer = max(answer, dp[R][C][i]);
	}
	COUT(answer);

	return 0;
}