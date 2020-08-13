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
#define SIZE 500000

int N, arr[51], dp[51][SIZE + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N) CIN(arr[i]);
	FUP(i, 1, SIZE) dp[0][i] = -1;
	dp[0][0] = 0;
	FUP(i, 1, N)
	{
		int h = arr[i];
		FUP(j, 0, SIZE)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= h && dp[i - 1][j - h] != -1)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - h] + h);
			}
			if (j < h && dp[i - 1][h - j] != -1)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][h - j] + j);
			}
			if (j + h <= SIZE && dp[i - 1][j + h] != -1)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j + h]);
			}
		}
	}
	dp[N][0] ? COUT(dp[N][0]) : COUT(-1);

	return 0;
}