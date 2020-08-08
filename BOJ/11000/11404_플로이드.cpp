#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;

int N, M;
int a, b, c;
int d[101][101];

void input()
{
	cin >> N >> M;
	fill(d[0], d[0] + 10201, INT_MAX);
	while (M--)
	{
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
}

void floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
				{
					d[i][j] = 0;
					continue;
				}
				if (d[i][k] != INT_MAX && d[k][j] != INT_MAX)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (d[i][j] == INT_MAX) d[i][j] = 0;
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	floyd();

	return 0;
}