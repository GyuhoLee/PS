#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[100][100];
long long answer[100][100] = { 0, };

void input();
void solve();

int main()
{
	input();
	solve();

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf_s("%lld", &arr[i][j]);
		}
	}
}

void solve()
{
	answer[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!answer[i][j] || !arr[i][j]) continue;
			if (j + arr[i][j] < N)
			{
				answer[i][j + arr[i][j]] += answer[i][j];
			}
			if (i + arr[i][j] < N)
			{
				answer[i + arr[i][j]][j] += answer[i][j];
			}
		}
	}
	printf("%lld", answer[N - 1][N - 1]);
}