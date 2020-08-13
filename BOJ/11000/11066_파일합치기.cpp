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

int T, N, dp[501][501], arr[501], sum[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		sum[0] = 0;
		CIN(N);
		FUP(i, 1, N)
		{
			CIN(arr[i]);
			dp[i][i] = 0;
			sum[i] = sum[i - 1] + arr[i];
		}
		FUP(range, 1, N - 1)
		{
			for(int l = 1; l + range <= N; l++)
			{
				int r = l + range;
				dp[l][r] = INT_MAX;
				for (int i = l; i < r; i++)
				{
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + sum[r] - sum[l - 1]);
				}
			}
		}
		COUT(dp[1][N]);
		ENDL;
	}

	return 0;
}