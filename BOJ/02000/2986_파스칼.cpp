#include <iostream>

int main()
{
	int N, K;
	scanf("%d", &N);
	K = 1;
	for (int i = 2; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			K = N / i;
			break;
		}
	}
	printf("%d\n", N - K);
	return 0;
}