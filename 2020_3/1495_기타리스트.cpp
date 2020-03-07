#include <bits/stdc++.h>
using namespace std;

int N, S, M;
int arr[101];
bool dp[101][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp, 0, sizeof(dp));
	cin >> N >> S >> M;
	dp[0][S] = true;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (!dp[i - 1][j]) continue;
			if (j + arr[i] <= M) dp[i][j + arr[i]] = true;
			if (j - arr[i] >= 0) dp[i][j - arr[i]] = true;
		}
	}
	for (int i = M; i >= 0; i--)
	{
		if (dp[N][i])
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;

	return 0;
}