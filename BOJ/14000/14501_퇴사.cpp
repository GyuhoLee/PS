#include <iostream>
#include <algorithm>
using namespace std;

int N;
int d[16], T[15], P[15];
int result = -1;

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d %d", &T[i], &P[i]);
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