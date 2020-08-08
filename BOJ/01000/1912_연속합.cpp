#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100000];
int answer = -1000;

void input();
void solve();

int main()
{
	input();
	solve();
	printf("%d", answer);

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &arr[i]);
}

void solve()
{
	answer = arr[0];
	for (int i = 0; i < N; i++)
	{
		arr[i] = max(arr[i], arr[i - 1] + arr[i]);
		answer = max(answer, arr[i]);
	}
}