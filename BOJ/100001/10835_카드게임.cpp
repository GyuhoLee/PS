#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;

int N;
int A[2000];
int B[2000];
int DP[2001][2001];
int answer = 0;

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &B[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			DP[i][j] = INT_MIN;
		}
	}
}

void solve()
{
	DP[0][0] = 0;
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (B[j] < A[i])
			{
				DP[i][j + 1] = max(DP[i][j + 1], DP[i][j] + B[j]);
				answer = max(DP[i][j + 1], answer);
			}
			DP[i + 1][j] = max(DP[i + 1][j], DP[i][j]);
			DP[i + 1][j + 1] = max(DP[i + 1][j + 1], DP[i][j]);
		}
	}
}

int main()
{
	input();
	solve();
	printf("%d", answer);

	return 0;
}