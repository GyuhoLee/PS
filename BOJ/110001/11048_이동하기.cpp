#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
int arr[1001][1001];
int dp[1001][1001];
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
		{
			cin >> arr[i][j];
		}
	}
	dp[1][1] = arr[1][1];
	FUP(i, 2, M) dp[1][i] = dp[1][i - 1] + arr[1][i];
	FUP(i, 2, N) dp[i][1] = dp[i - 1][1] + arr[i][1];
	FUP(i, 2, N)
	{
		FUP(j, 2, M)
		{
			dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[N][M];

	return 0;
}