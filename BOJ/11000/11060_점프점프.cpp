#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;

int N;
int arr[1000];
int d[1000];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		d[i] = INT_MAX;
	}
}

void solve()
{
	d[0] = 0;
	for (int i = 0; i < N; i++)
	{
		if (d[i] == INT_MAX) continue;
		for (int j = i + 1; j <= i + arr[i]; j++)
		{
			d[j] = min(d[j], d[i] + 1);
			if (j == N - 1) break;
		}
	}
	if (d[N - 1] == INT_MAX) d[N - 1] = -1;
	printf("%d", d[N - 1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	solve();

	return 0;
}