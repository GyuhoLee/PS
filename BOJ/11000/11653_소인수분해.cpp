#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N != 1)
	{
		for (int i = 2; i <= N; i++)
		{
			while (1)
			{
				if (N % i == 0)
				{
					printf("%d\n", i);
					N /= i;
				}
				else break;
			}
		}
	}

	return 0;
}