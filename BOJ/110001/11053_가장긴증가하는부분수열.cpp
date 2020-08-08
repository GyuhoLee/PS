#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000];
int d[1000];

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
		d[i] = 1;
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
				temp = max(d[j], temp);
		}
		d[i] = temp + 1;
		answer = max(answer, d[i]);
	}
	return answer;
}