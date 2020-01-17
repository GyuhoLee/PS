#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

char arr[8][8][8];
int dx[9] = { 1, 1, 1, -1, -1, -1, 0, 0, 0 };
int dy[9] = { 1, 0, -1, 1, 0, -1, 1, 0, -1 };
int answer = 0;

struct node
{
	int x, y, time;
	node(int a, int b, int c) : x(a), y(b), time(c) {};
};

void input()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				arr[i][j][k] = '.';
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf_s("%c", &arr[i][j][0]);
			for (int k = i + 1; k < 8; k++)
			{
				arr[k][j][k - i] = arr[i][j][0];
			}
		}
		getchar();
	}
}

void BFS()
{
	queue<node> q;
	q.push(node(7, 0, 0));
	while (!q.empty())
	{
		node temp(q.front().x, q.front().y, q.front().time);
		q.pop();
		if (temp.time >= 7)
		{
			answer = 1;
			break;
		}
		for (int i = 0; i < 9; i++)
		{
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8)
			{
				if (arr[nx][ny][temp.time] == '.' && arr[nx][ny][temp.time + 1] == '.')
				{
					q.push(node(nx, ny, temp.time + 1));
				}
			}
		}
	}
}

int main()
{
	input();
	BFS();
	printf("%d", answer);
	return 0;
}