#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;

int N, M, y, x, K;
int dice[6] = { 0, 0, 0, 0, 0, 0 };
int arr[20][20];

void input()
{
	memset(arr, 0, sizeof(arr));
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
}

//µ¿1¼­2ºÏ3³²4
void move(int k)
{
	int temp = -1;
	switch (k)
	{
	case 1:
		if (x + 1 >= M) return;
		x++;
		temp = dice[3];
		for (int i = 3; i > 0; i--) dice[i] = dice[i - 1];
		dice[0] = temp;
		break;
	case 2:
		if (x == 0) return;
		x--;
		temp = dice[0];
		for (int i = 0; i < 3; i++) dice[i] = dice[i + 1];
		dice[3] = temp;
		break;
	case 3://0425
		if (y == 0) return;
		y--;
		temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[5];
		dice[5] = temp;
		break;
	case 4:
		if (y + 1 >= N) return;
		y++;
		temp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[4];
		dice[4] = temp;
		break;

	}
	if (arr[y][x])
	{
		dice[2] = arr[y][x];
		arr[y][x] = 0;
	}
	else
	{
		arr[y][x] = dice[2];
	}
	cout << dice[0] << '\n';
}

void solve()
{
	int k;
	cin >> k;
	move(k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	while (K--)
	{
		solve();
	}
	
	return 0;
}
