#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[1000][3], dp[1000][3], ans = 1e9;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	for (int color = 0; color < 3; color++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == color) dp[0][i] = arr[0][i];
			else dp[0][i] = 1e9;
		}
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + arr[i][j];
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (i != color) ans = min(ans, dp[N - 1][i]);
		}
	}
	cout << ans;

	return 0;
}