#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int arr[100][100];
bool visited[100][100];
int time[100][100];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void input()
{
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &arr[i][j]);
		}
	}
}

void BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	time[0][0] = 1;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];
			if (ny >= 0 && nx >= 0 && ny < N && nx < M)
			{
				if ((!visited[ny][nx]) && arr[ny][nx])
				{
					visited[ny][nx] = true;
					time[ny][nx] = time[temp.first][temp.second] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main()
{
	input();
	BFS();
	printf("%d", time[N - 1][M - 1]);

	return 0;
}