#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[25][25];
bool visited[25][25];
int roomNum = 0;
int room[625] = { 0, };
//¼­ ºÏ µ¿ ³²
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf_s("%1d", &arr[i][j]);
		}
	}
}

void DFS(int y, int x)
{
	visited[y][x] = true;
	room[roomNum]++;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < N && nx >= 0 && nx < N)
		{
			if (!visited[ny][nx] && arr[ny][nx])
			{
				DFS(ny, nx);
			}
		}
	}
}


int main()
{
	input();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && arr[i][j])
			{
				room[roomNum] = 0;
				DFS(i, j);
				roomNum++;
			}
		}
	}

	sort(room, room + roomNum);

	printf("%d\n", roomNum);
	for (int i = 0; i < roomNum; i++)
	{
		printf("%d\n", room[i]);
	}

	return 0;
}