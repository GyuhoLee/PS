#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[301];
int answer[301];

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
	for (int i = 1; i <= N; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void solve()
{
	answer[0] = 0;
	answer[1] = arr[1];
	answer[2] = arr[1] + arr[2];
	for (int i = 3; i <= N; i++)
	{
		answer[i] = max(arr[i - 1] + answer[i - 3], answer[i - 2]);
		answer[i] += arr[i];
	}
	printf("%d", answer[N]);
}