#include <iostream>
using namespace std;
#define MOD 1000000

int dp[1001][2][3], N;
// 일, 지각횟수 결석 연속

int main()
{
	cin >> N;
	dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
		dp[i][1][0] = (dp[i][0][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 1; k < 3; k++)
			{
				dp[i][j][k] = dp[i - 1][j][k - 1];
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < 2; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			ans += dp[N][j][k];
			ans %= MOD;
		}
	}
	cout << ans;

	return 0;
}