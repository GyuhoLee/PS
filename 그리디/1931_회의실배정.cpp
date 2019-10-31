#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> arr[100000];
int d[100000];

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
		scanf_s("%d %d", &arr[i].second, &arr[i].first);
	sort(arr, arr + N );
}


int solve()
{
	int answer = 0;
	int time = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].second >= time)
		{
			time = arr[i].first;
			answer++;
		}
	}
	return answer;
}