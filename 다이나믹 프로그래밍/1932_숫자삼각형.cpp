#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[501][501];

void input();
int solve();

int main()
{
	input();
	printf("%d", solve());

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
}

int solve()
{
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1) arr[i][j] = arr[i - 1][1] + arr[i][j];
			else if (j == i) arr[i][j] = arr[i - 1][j - 1] + arr[i][j];
			else arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + arr[i][j];
		}
	}
	int answer = 0;
	
	for (int i = 1; i <= N; i++)
		answer = max(answer, arr[N][i]);
	
	return answer;
}