#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int R, C, T;
int arr[50][50];
int copyArr[50][50];
int cleaner;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void input()
{
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1) cleaner = i;
		}
	}
}

void virus()
{
	memset(copyArr, 0, sizeof(copyArr));
	copyArr[cleaner][0] = -1;
	copyArr[cleaner - 1][0] = -1;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] <= 0) continue;

			int temp = arr[i][j] / 5;
			int tempCnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C || arr[ny][nx] == -1) continue;
				copyArr[ny][nx] += temp;
				tempCnt++;
			}
			copyArr[i][j] += (arr[i][j] - temp * tempCnt);
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = copyArr[i][j];
		}
	}
}

void clean()
{
	for (int i = cleaner - 2; i > 0; i--)
	{
		arr[i][0] = arr[i - 1][0];
	}
	for (int i = 0; i < C - 1; i++)
	{
		arr[0][i] = arr[0][i + 1];
	}
	for (int i = 0; i < cleaner - 1; i++)
	{
		arr[i][C - 1] = arr[i + 1][C - 1];
	}
	for (int i = C - 1; i > 1; i--)
	{
		arr[cleaner - 1][i] = arr[cleaner - 1][i - 1];
	}
	arr[cleaner - 1][1] = 0;

	for (int i = cleaner + 1; i < R - 1; i++)
	{
		arr[i][0] = arr[i + 1][0];
	}
	for (int i = 0; i < C - 1; i++)
	{
		arr[R - 1][i] = arr[R - 1][i + 1];
	}
	for (int i = R - 1; i > cleaner; i--)
	{
		arr[i][C - 1] = arr[i - 1][C - 1];
	}
	for (int i = C - 1; i > 1; i--)
	{
		arr[cleaner][i] = arr[cleaner][i - 1];
	}
	arr[cleaner][1] = 0;
}

void answer()
{
	int ret = 2;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			ret += arr[i][j];
		}
	}
	cout << ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	while (T--)
	{
		virus();
		clean();
	}
	answer();

	return 0;
}