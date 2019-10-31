#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000];
int up[1000];
int down[1000];

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
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &arr[i]);
		up[i] = 1;
		down[i] = 1;
	}
}

int solve()
{
	int answer = 1;
	for (int i = 1; i < N; i++)
	{
		int temp = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[i])
			{
				temp = max(up[j], temp);
			}
		}
		up[i] = temp + 1;;
	}

	for (int i = N - 2; i >= 0; i--)
	{
		int temp = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[i])
			{
				temp = max(down[j], temp);
			}
		}
		down[i] = temp + 1;;
	}

	for (int i = 0; i < N; i++)
		answer = max(answer, up[i] + down[i] - 1);

	return answer;
}