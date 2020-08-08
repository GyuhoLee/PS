#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100];
long long int dp[101][21];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void DP()
{
	memset(dp, 0, sizeof(dp));
	dp[0][arr[0]] = 1;
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i - 1][j])
			{
				if (j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[N - 2][arr[N - 1]];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	DP();

	return 0;
}