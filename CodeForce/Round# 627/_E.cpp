#include <bits/stdc++.h>
using namespace std;

int N, H, L, R;
int dp[2001][2001];
int arr[2001];

bool can(int num)
{
	if (L <= num && R >= num) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> H >> L >> R;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(dp, -1, sizeof(dp));

	if (can(arr[0])) dp[0][arr[0]] = 1;
	else dp[0][arr[0]] = 0;
	if (can(arr[0] - 1)) dp[0][arr[0] - 1] = 1;
	else dp[0][arr[0] - 1] = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (dp[i - 1][j] != -1)
			{
				if (can((j + arr[i]) % H)) dp[i][(j + arr[i]) % H] = max(dp[i][(j + arr[i]) % H], dp[i - 1][j] + 1);
				else dp[i][(j + arr[i]) % H] = max(dp[i][(j + arr[i]) % H], dp[i - 1][j]);

				if (can((j + arr[i] - 1) % H)) dp[i][(j + arr[i] - 1) % H] = max(dp[i][(j + arr[i] - 1) % H], dp[i - 1][j] + 1);
				else dp[i][(j + arr[i] - 1) % H] = max(dp[i][(j + arr[i] - 1) % H], dp[i - 1][j]);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < H; i++)
	{
		answer = max(answer, dp[N - 1][i]);
	}
	cout << answer;

	return 0;
}