#include <bits/stdc++.h>
using namespace std;

int N;
int a, b, c;
int d[101][101];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> d[i][j];
		}
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
				if (d[i][k] != 0 && d[k][j] != 0)
				{
					d[i][j] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
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