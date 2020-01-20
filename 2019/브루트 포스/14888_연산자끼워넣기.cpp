#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[11];
int arr[4];
int max_ans = -1000000001;
int min_ans = 1000000001;

void input();
void solve(int cnt, int ans);

int main()
{
	input();
	solve(0, num[0]);
	printf("%d\n%d", max_ans, min_ans);

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &num[i]);
	for (int i = 0; i < 4; i++)
		scanf_s("%d", &arr[i]);
}

void solve(int cnt, int ans)
{
	if (cnt == N - 1)
	{
		min_ans = min(ans, min_ans);
		max_ans = max(ans, max_ans);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (arr[i])
		{
			arr[i]--;
			switch (i)
			{
			case 0:
				solve(cnt + 1, ans + num[cnt + 1]);
				break;
			case 1:
				solve(cnt + 1, ans - num[cnt + 1]);
				break;
			case 2:
				solve(cnt + 1, ans * num[cnt + 1]);
				break;
			case 3:
				solve(cnt + 1, ans / num[cnt + 1]);
				break;
			}
			arr[i]++;
		}
	}
}