#include <bits/stdc++.h>
using namespace std;

int N;
int arr[500][500];
int dp[500][500];
int answer = 1;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = 0;
		}
	}
}

int DFS(int y, int x)
{
	if (dp[y][x]) return dp[y][x];
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || arr[y][x] >= arr[ny][nx]) continue;
		dp[y][x] = max(dp[y][x], DFS(ny, nx) + 1);;
	}
	return dp[y][x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer= max(answer, DFS(i, j));
		}
	}
	cout << answer;

	return 0;
}