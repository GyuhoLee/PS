#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int R, C;
int arr[1000][1000]; // -1 : 벽  // 0~ : 몇 분에 불이 붙냐 // -2 : 임시값
bool visited[1000][1000];
pair<int, int> now;
queue<pair<int, int>> Q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int answer = -1;

struct PT
{
	int first;
	int second;
	int time;
	PT(int a, int b, int c) : first(a), second(b), time(c) {};
};

void input()
{
	answer = -1;
	scanf_s("%d %d", &C, &R);
	char temp;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			visited[i][j] = false;
			cin >> temp;
			switch (temp)
			{
			case '#': arr[i][j] = -1;
				break;
			case '*': arr[i][j] = 0;
				Q.push(make_pair(i, j));
				break;
			case '@': now = make_pair(i, j);
				visited[i][j] = true;
			default: arr[i][j] = -2;
				break;
			}
		}
	}
}

void BFS_fire()
{
	while (!Q.empty())
	{
		pair<int, int> point = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = point.first + dx[i];
			int ny = point.second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < R && ny < C)
			{
				if (arr[nx][ny] == -2)
				{
					Q.push(make_pair(nx, ny));
					arr[nx][ny] = arr[point.first][point.second] + 1;
				}
			}
		}
	}
}

void BFS_move()
{
	queue<PT> q;
	PT temp(now.first, now.second, 0);
	PT point(0, 0, 0);
	q.push(temp);
	while (!q.empty() && answer == -1)
	{
		point.first = q.front().first;
		point.second = q.front().second;
		point.time = q.front().time;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = point.first + dx[i];
			int ny = point.second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < R && ny < C)
			{
				if (arr[nx][ny] == -1)
				{
					continue;
				}
				else if (!visited[nx][ny] && (arr[nx][ny] > point.time + 1 || arr[nx][ny] == -2))
				{
					temp.first = nx;
					temp.second = ny;
					temp.time = point.time + 1;
					visited[nx][ny] = true;
					q.push(temp);
				}
			}
			else
			{
				answer = point.time + 1;
				break;
			}
		}
	}
}

int main()
{
	int T;
	scanf_s("%d", &T);
	while (T--)
	{
		input();
		BFS_fire();
		BFS_move();
		if (answer == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", answer);
	}

	return 0;
}