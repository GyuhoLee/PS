#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int arr[500][500];
int visited[500][500];
int dy[3] = { 0, 1, -1 };
int dx[3] = { 1, 0, 0 };
int answer = 0;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
}

void DFS(int y, int x, int sum, int cnt)
{
	visited[y][x] = true;
	sum += arr[y][x];
	if (cnt == 4)
	{
		answer = max(answer, sum);
		visited[y][x] = false;
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < N && nx < M && ny >= 0 && nx >= 0)
		{
			if (!visited[ny][nx])
			{
				DFS(ny, nx, sum, cnt + 1);
			}
		}
	}
	visited[y][x] = false;
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			int line = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
			if (i != 0)
			{
				answer = max(answer, line + arr[i - 1][j + 1]);
			}
			if (i != N - 1)
			{
				answer = max(answer, line + arr[i + 1][j + 1]);
			}
		}
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int line = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
			if (j != 0)
			{
				answer = max(answer, line + arr[i + 1][j - 1]);
			}
			if (j != M - 1)
			{
				answer = max(answer, line + arr[i + 1][j + 1]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			DFS(i, j, 0, 1);
		}
	}
	solve();
	cout << answer;

	return 0;
}