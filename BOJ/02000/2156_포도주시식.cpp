#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10001];
int d[10001];

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
		scanf_s("%d", &arr[i]);
}

int solve()
{
	d[0] = 0;
	d[1] = arr[1];
	d[2] = arr[1] + arr[2];
	for (int i = 2; i <= N; i++)
	{
		d[i] = max(d[i - 1], d[i - 2] + arr[i]);
		d[i] = max(d[i - 3] + arr[i - 1] + arr[i], d[i]);
		if (i >= 4 && d[i - 4] + arr[i - 1] + arr[i] > d[i])
		{
			if (i >= 5 && d[i - 4] == d[i - 5])
				d[i] = d[i - 4] + arr[i - 1] + arr[i] + arr[i - 4];
			else
				d[i] = d[i - 4] + arr[i - 1] + arr[i];
		}
	}
	return d[N];
}