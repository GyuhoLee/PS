#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> arr[100];
int d[100];

void input();
int solve();

int main()
{
	input();
	printf("%d", solve());

	return 0;
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d %d", &arr[i].first, &arr[i].second);

	sort(arr, arr + N);
}

int solve()
{
	int answer = 1;
	d[0] = 1;
	for (int i = 1; i < N; i++)
	{
		int temp = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j].second < arr[i].second)
				temp = max(d[j], temp);
		}
		d[i] = temp + 1;
		answer = max(answer, d[i]);
	}
	return answer;
}