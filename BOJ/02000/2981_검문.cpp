#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0) return b;
	return GCD(b, a % b);
}

int N;
int arr[100];

void input();
int solve();
void answer();

int main()
{
	input();
	answer();

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &arr[i]);
	sort(arr, arr + N);
}

int solve()
{
	int ans[100];
	for (int i = 1; i < N; i++)
		ans[i] = arr[i] - arr[i - 1];
	if (N == 2) return ans[1];
	int temp = GCD(ans[1], ans[2]);
	for (int i = 3; i < N; i++)
	{
		temp = GCD(temp, ans[i]);
	}
	return temp;
}

void answer()
{
	int temp = solve();
	for (int i = 2; i <= temp / 2; i++)
	{
		if (temp % i == 0) printf("%d ", i);
	}
	printf("%d", temp);
}