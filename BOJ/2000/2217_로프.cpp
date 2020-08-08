#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100000];

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
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
}

int solve()
{
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer = max(answer, arr[i] * (N - i));
	}
	return answer;
}