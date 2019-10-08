#include <iostream>
using namespace std;

int N;
int solve(int n);


int main()
{
	scanf_s("%d", &N);
	printf("%d", solve(N));


	return 0;
}

int solve(int n)
{
	int gop = (n + 1) / 2;
	int answer = 1;
	while (gop--)
	{
		answer = (answer * 2) % 16769023;
	}
	return answer;
}