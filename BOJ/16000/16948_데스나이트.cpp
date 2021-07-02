#include <iostream>
#include <queue>
using namespace std;

int dy[6] = { -2, -2, 0, 0, 2, 2 };
int dx[6] = { -1, 1, -2, 2, -1, 1 };
int N, r1, c1, r2, c2, dist[200][200];

int main()
{
	cin >> N >> r1 >> c1 >> r2 >> c2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dist[i][j] = -1;
		}
	}
	dist[r1][c1] = 0;
	queue<pair<int, int>> q;
	q.push({ r1, c1 });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		int d = dist[y][x];
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || dist[ny][nx] != -1) continue;
			dist[ny][nx] = d + 1;
			q.push({ ny, nx });
		}
	}
	cout << dist[r2][c2];

	return 0;
}