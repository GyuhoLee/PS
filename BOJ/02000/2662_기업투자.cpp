#include <iostream>
using namespace std;

int N, M, dp[21][301], arr[21][301], before[21][301], ans[21];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int money;
		cin >> money;
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[j][money];
		}
	}
	for (int i = 1; i <= M; i++)
	{
		for(int j = N; j >= 0; j--)
		{
			for (int k = 0; j - k >= 0; k++)
			{
				if (dp[i - 1][j - k] + arr[i][k] > dp[i][j])
				{
					before[i][j] = k;
					dp[i][j] = dp[i - 1][j - k] + arr[i][k];
				}
			}
		}
	}
	int i = M, j = N;
	while (i >= 1)
	{
		ans[i] = before[i][j];
		j = j - before[i][j];
		i--;
	}
	cout << dp[M][N] << '\n';
	for (int i = 1; i <= M; i++)
	{
		cout << ans[i] << ' ';
	}
}