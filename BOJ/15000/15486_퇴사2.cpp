#include <bits/stdc++.h>
using namespace std;

int N;
int d[1500001], T[1500000], P[1500000];
int result = -1;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> T[i] >> P[i];
	}
}

void DP()
{
	for (int i = 0; i < N; i++)
	{
		if (i + T[i] <= N)
		{
			d[i + T[i]] = max(d[i + T[i]], d[i] + P[i]);
			result = max(result, d[i + T[i]]);
		}
		d[i + 1] = max(d[i + 1], d[i]);
		result = max(result, d[i + 1]);
	}
}

int main()
{
	input();
	DP();
	printf("%d", result);

	return 0;
}