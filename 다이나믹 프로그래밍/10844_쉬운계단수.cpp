#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[101][10];

void setting();
void solve();

int main()
{
	setting();
	solve();

	return 0;
}

void setting()
{
	for (int i = 1; i < 10; i++)
		arr[1][i] = 1;
	arr[1][0] = 0;
	for (int i = 2; i < 101; i++)
	{
		arr[i][0] = arr[i - 1][1];
		for (int j = 1; j < 9; j++)
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		arr[i][9] = arr[i - 1][8];
	}
}

void solve()
{
	int N;
	scanf_s("%d", &N);
	long long int answer = 0;
	for (int i = 0; i < 10; i++)
		answer = (answer + arr[N][i]) % 1000000000;
	printf("%lld", answer);

}