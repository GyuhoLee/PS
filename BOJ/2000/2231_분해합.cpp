#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(int n);

int main()
{
	int N;
	scanf_s("%d", &N);
	int answer = 0;
	for (int i = 1; i < N; i++)
	{
		if (sum(i) == N)
		{
			answer = i;
			break;
		}
	}
	cout << answer;


	return 0;
}

int sum(int n)
{
	int temp = n;
	while (n)
	{
		temp = temp + n % 10;
		n /= 10;
	}
	return temp;
}