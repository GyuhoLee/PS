#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int M, N;
int arr[50][50];
bool visited[50][50];
int roomCheck[50][50];
int roomNum = 0;
int room[2500] = { 0, };
//¼­ ºÏ µ¿ ³²
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
int answer2 = 0;
int answer3 = 0;

void input()
{
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
}

void DFS(int y, int x)
{
	visited[y][x] = true;
	roomCheck[y][x] = roomNum;
	room[roomNum]++;
	for (int i = 0; i < 4; i++)
	{
		int temp = pow(2, i);
		if(arr[y][x] / temp % 2 == 1) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < M && nx >= 0 && nx < N)
		{
			if (!visited[ny][nx])
			{
				DFS(ny, nx);
			}
		}
	}
}

void solve()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (roomCheck[i][j] != roomCheck[i][j + 1])
			{
				answer3 = max(room[roomCheck[i][j]] + room[roomCheck[i][j + 1]], answer3);
			}
		}
	}

	for (int i = 0; i < M - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (roomCheck[i][j] != roomCheck[i + 1][j])
			{
				answer3 = max(room[roomCheck[i][j]] + room[roomCheck[i + 1][j]], answer3);
			}
		}
	}
}

int main()
{
	input();
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				room[roomNum] = 0;
				DFS(i, j);
				answer2 = max(answer2, room[roomNum]);
				roomNum++;
			}
		}
	}

	solve();

	printf("%d\n", roomNum);
	printf("%d\n", answer2);
	printf("%d\n", answer3);

	return 0;
}