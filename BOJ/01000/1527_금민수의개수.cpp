#include <iostream>
#include <algorithm>
using namespace std;

int A, B;
int answer = 0;

void input()
{
	scanf_s("%d %d", &A, &B);
}

void solve(long long int num)
{
	if (num > B) return;
	
	if (A <= num && num <= B) answer++;

	solve(num * 10 + 4);
	solve(num * 10 + 7);
}

int main()
{
	input();
	solve(4);
	solve(7);
	printf("%d", answer);

	return 0;
}