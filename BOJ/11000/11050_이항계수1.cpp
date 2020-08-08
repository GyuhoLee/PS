#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int answer = 1;
	for (int i = N - K + 1; i <= N; i++)
		answer *= i;
	for (int i = K; i > 1; i--)
		answer /= i;
	printf("%d", answer);
}