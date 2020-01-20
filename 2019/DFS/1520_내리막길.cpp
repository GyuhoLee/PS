#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
int arr[500][500];
int answer[500][500];
vector<int> sx = { 1, -1, 0, 0 };
vector<int> sy = { 0, 0, 1, -1 };

void input();
int move(int i, int j);

int main()
{
	input();
	printf("%d", move(M - 1, N - 1));

	return 0;
}

void input()
{
 	scanf_s("%d %d", &M, &N);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf_s("%d", &arr[i][j]);
			answer[i][j] = -1;
		}
	}
}

int move(int i, int j)
{
	if (i == 0 && j == 0)
	{
		return 1;
	}
	if (answer[i][j] == -1)
	{
		answer[i][j] = 0;
		for (int k = 0; k < 4; k++)
		{
			int tx = i + sx[k];
			int ty = j + sy[k];
			if (tx < 0 || ty < 0 || tx >= M || ty >= N || arr[tx][ty] <= arr[i][j]) continue;
			answer[i][j] += move(tx, ty);
		}
	}
	return answer[i][j];
}