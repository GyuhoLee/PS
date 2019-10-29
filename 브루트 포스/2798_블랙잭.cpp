#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int answer = 0;
int arr[100];

void input();
void choice();

int main()
{
	input();
	choice();
	printf("%d", answer);

	return 0;
}

void input()
{
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void choice()
{
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int sum = arr[i] + arr[j] + arr[k];
				if (sum <= M)
				{
					answer = max(answer, sum);
				}
			}
		}
	}
}