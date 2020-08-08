#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[1000][1000];
int leftD[1000][1000];
int rightD[1000][1000];
int dp[1000][1000];

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
}

void solve()
{
	dp[0][0] = arr[0][0];
	for (int i = 1; i < M; i++) dp[0][i] = dp[0][i - 1] + arr[0][i];
	
	for (int i = 1; i < N; i++)
	{
		leftD[i][0] = dp[i - 1][0] + arr[i][0];
		for (int j = 1; j < M; j++) leftD[i][j] = max(dp[i - 1][j], leftD[i][j - 1]) + arr[i][j];

		rightD[i][M - 1] = dp[i - 1][M - 1] + arr[i][M - 1];
		for (int j = M - 2; j >= 0; j--) rightD[i][j] = max(dp[i - 1][j], rightD[i][j + 1]) + arr[i][j];

		for (int j = 0; j < M; j++)
			dp[i][j] = max(leftD[i][j], rightD[i][j]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	cout << dp[N - 1][M - 1];

	return 0;
}