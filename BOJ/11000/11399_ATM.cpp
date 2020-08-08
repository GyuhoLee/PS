#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001];

void input();
long long int solve();

int main()
{
	input();
	printf("%lld", solve());

	return 0;
}

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
}

long long int solve()
{
	long long int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer = answer + arr[i] * (N - i);
	}
	return answer;
}