#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int T, M, N, K;
int arr[50][50] = { 0, };
stack<pair<int, int>> S;
int answer = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void input()
{
	answer = 0;
	scanf_s("%d %d %d", &M, &N, &K);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < K; i++)
	{
		int tx, ty;
		scanf_s("%d %d", &tx, &ty);
		arr[tx][ty] = 1;
		S.push(make_pair(tx, ty));
	}
}

void DFS(int x, int y)
{
	arr[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && 0 <= ny && M > nx && N > ny)
		{
			if (arr[nx][ny])
			{
				DFS(nx, ny);
			}
		}
	}
}

void solve()
{
	pair<int, int> temp;
	while (!S.empty())
	{
		temp = S.top();
		S.pop();
		if (arr[temp.first][temp.second])
		{
			answer++;
			DFS(temp.first, temp.second);
		}
	}
}

int main()
{
	scanf_s("%d", &T);
	while (T--)
	{
		input();
		solve();
		printf("%d\n", answer);
	}
}