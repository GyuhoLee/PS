#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int r, c, d;
int arr[50][50];
//ºÏµ¿³²¼­
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int answer = 0;
bool finish = false;

void input()
{
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
}

void goBack()
{
	int ny = r + dy[(d + 2) % 4];
	int nx = c + dx[(d + 2) % 4];
	if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 1)
	{
		finish = true;
		return;
	}
	r = ny;
	c = nx;
}

void solve()
{
	while (!finish)
	{
		if (!arr[r][c])
		{
			arr[r][c] = 2;
			answer++;
		}
		for (int i = 3; i >= 0; i--)
		{
			int ny = r + dy[(d + i) % 4];
			int nx = c + dx[(d + i) % 4];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx])
			{
				if (!i)
				{
					d = (d + i) % 4;
					goBack();
				}
				continue;
			}
			r = ny;
			c = nx;
			d = (d + i) % 4;
			break;
		}
	}
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();

	return 0;
}