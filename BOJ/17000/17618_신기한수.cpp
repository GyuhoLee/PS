#include <iostream>
#include <algorithm>
using namespace std;

int N;

void input()
{
	scanf("%d", &N);
}
int solve()
{
	if (N <= 10) return N;
	int ret = 10;
	for (int i = 11; i <= N; i++)
	{
		int temp = i;
		int answer = 0;
		while (temp)
		{
			answer += (temp % 10);
			temp /= 10;
		}
		if (!(i % answer)) ret++;
	}
	return ret;
}

int main()
{
	input();
	printf("%d", solve());

	return 0;
}