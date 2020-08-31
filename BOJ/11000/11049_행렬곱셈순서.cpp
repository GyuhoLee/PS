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

ll N, dp[501][501];
pair<int, int> arr[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N)
	{
		CIN2(arr[i].first, arr[i].second);
	}
	FUP(range, 1, N - 1)
	{
		for (int i = 1; i + range <= N; i++)
		{
			int j = i + range;
			dp[i][j] = 1e18;
			FUP(mid, i, j - 1)
			{
				dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + arr[i].first * arr[j].second * arr[mid].second);
			}
		}
	}
	COUT(dp[1][N]);

	return 0;
}