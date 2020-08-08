#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define INF 10001
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, K;
int arr[100];
int dp[10001];

int solve(int num)
{
	if (num < 0) return INF;
	if (dp[num] != -1) return dp[num];
	dp[num] = INF;
	FUP(i, 0, N - 1)
	{
		dp[num] = min(dp[num], solve(num - arr[i]) + 1);
	}
	return dp[num];
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(dp, -1);
	dp[0] = 0;
	cin >> N >> K;
	FUP(i, 0, N - 1) cin >> arr[i];
	solve(K);
	if (dp[K] > 10000) dp[K] = -1;
	cout << dp[K];

	return 0;
}