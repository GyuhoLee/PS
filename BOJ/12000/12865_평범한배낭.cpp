#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M;
pair<int, int> arr[101];
int d[101][100001];

void input();
bool compare(pair<int, int> a, pair<int, int> b)
{
	return (double)a.second / a.first < (double)b.second / b.first;
}
int solve();

int main()
{
	input();
	printf("%d", solve());
}

void input()
{
	scanf_s("%d %d", &N , &M);
	for (int i = 1; i <= N; i++)
		scanf_s("%d %d", &arr[i].first, &arr[i].second);
	sort(arr, arr + N, compare);
	
}

int solve()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			d[i][j] = d[i - 1][j];
			if (j - arr[i].first >= 0)
			{
				d[i][j] = max(d[i][j], d[i - 1][j - arr[i].first] + arr[i].second);
			}
		}
	}
	return d[N][M];
}