#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[10];

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
	scanf_s("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &arr[i]);
}

int solve()
{
	int answer = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		answer = answer + K / arr[i];
		K = K % arr[i];
		if (!K) break;
	}
	return answer;
}