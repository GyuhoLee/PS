#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[50][50];
int answer = 0;

void change(int y, int x)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[y + i][x + j] = (arr[y + i][x + j] + 1) % 2;
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			scanf_s("%1d", &temp);
			if (arr[i][j] == temp) arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}

	if (N < 3 || M < 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j])
				{
					cout << -1;
					return 0;
				}
			}
		}
		cout << 0;
		return 0;
	}
	
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (arr[i][j])
			{
				change(i, j);
				answer++;
			}
			if (i == N - 3 && arr[i + 1][j] + arr[i + 2][j] > 0)
			{
				cout << -1;
				return 0;
			}
			if (j == M - 3 && arr[i][j + 1] + arr[i][j + 2] > 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (arr[N - i][M - j])
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << answer;



	return 0;
}