#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;

int N;
int d[20][20];
int arr[20][20];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> d[i][j];
			arr[i][j] = d[i][j];
		}
	}
}

void floyd()
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == j)
				{
					arr[i][j] = 0;
					continue;
				}
				if (i == k || j == k) continue;

				if (d[i][j] > d[i][k] + d[k][j])
				{
					cout << "-1";
					return;
				}
				
				if (d[i][j] == d[i][k] + d[k][j])
				{
					arr[i][j] = 0;
				}
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer += arr[i][j];
		}
	}
	cout << answer / 2;
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