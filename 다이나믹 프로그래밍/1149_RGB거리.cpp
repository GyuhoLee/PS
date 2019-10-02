#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001][3];
int answer[1001][3] = { 0, };

void input();
void solve();

int main()
{
	input();
	solve();

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf_s("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
}
void solve()
{
	for(int i = 0; i < 3; i++) answer[1][i] = arr[1][i];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			answer[i][j] = min(answer[i - 1][(j + 1) % 3], answer[i - 1][(j + 2) % 3]) + arr[i][j];
		}
	}
	int result = min(answer[N][0], answer[N][1]);
	result = min(answer[N][2], result);
	printf("%d", result);
}