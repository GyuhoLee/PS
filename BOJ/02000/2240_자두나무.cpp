#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int T, W;
int arr[1001];
int d[1001][32][2];

void input()
{
	cin >> T >> W;
	for (int i = 1; i <= T; i++)
	{
		cin >> arr[i];
		arr[i]--;
	}
	memset(d, -1, sizeof(d));
	d[0][0][0] = arr[0] = 0;
}

void solve()
{
	for (int i = 1; i <= T; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (d[i - 1][j][0] != -1)
			{
				if (!arr[i])
				{
					d[i][j][0] = max(d[i][j][0], d[i - 1][j][0] + 1);
				}
				else
				{
					d[i][j][0] = max(d[i][j][0], d[i - 1][j][0]);
					d[i][j + 1][1] = max(d[i][j + 1][1], d[i - 1][j][0] + 1);
				}
			}
			if (d[i - 1][j][1] != -1)
			{
				if (arr[i])
				{
					d[i][j][1] = max(d[i][j][1], d[i - 1][j][1] + 1);
				}
				else
				{
					d[i][j][1] = max(d[i][j][1], d[i - 1][j][1]);
					d[i][j + 1][0] = max(d[i][j + 1][0], d[i - 1][j][1] + 1);
				}
			}
		}
	}

	int answer = 0;
	for (int i = 0; i <= W; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			answer = max(answer, d[T][i][j]);
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