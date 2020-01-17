#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, M, T;
int arr[101][101]; //  0은 빈 공간, 1은 마법의 벽, 2는 그람이 놓여있는 공간
bool visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int answer = 10001;

struct node
{
	int x, y, time;
	node(int a, int b, int c) : x(a), y(b), time(c) {};
};

void input()
{
	scanf_s("%d %d %d", &N, &M, &T);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf_s("%d", &arr[i][j]);
			visited[i][j] = false;
		}
	}
	visited[1][1] = true;
}

void BFS()
{
	queue<node> q;
	q.push(node(1, 1, 0));
	bool find = false;
	while (!q.empty() && !find)
	{
		node temp(q.front().x, q.front().y, q.front().time);
		q.pop();
		if (temp.x == N && temp.y == M)
		{
			answer = min(answer, temp.time);
			break;
		}
		if (temp.time >= answer || temp.time > T) break;
		for (int i = 0; i < 4; i++)
		{
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx > 0 && ny > 0 && nx <= N && ny <= M)
			{
				if (!visited[nx][ny] && arr[nx][ny] != 1)
				{
					visited[nx][ny] = true;
					if (arr[nx][ny] == 2)
					{
						int aTemp = temp.time + 1 + abs(N - nx) + abs(M - ny);
						if (aTemp <= T) answer = min(answer, aTemp);
					}
					else
					{
						q.push(node(nx, ny, temp.time + 1));
					}
				}
			}
		}
	}
}

int main()
{
	input();
	BFS();
	if (answer == 5001) printf("Fail");
	else printf("%d", answer);
	return 0;
}