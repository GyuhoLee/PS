#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int N, M;
int A, B, C;
vector<pair<int, pair<int, int>>> arr;
int d[501];
bool infinity = false;

void input()
{
	fill(d, d + 501, INT_MAX);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		arr.push_back(make_pair(A, make_pair(B, C)));
	}
}

void solve()
{
	d[1] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int u = arr[j].first;
			int v = arr[j].second.first;
			int w = arr[j].second.second;
			if (d[u] != INT_MAX)
			{
				d[v] = d[u] + w < d[v] ? d[u] + w : d[v];
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		int u = arr[i].first;
		int v = arr[i].second.first;
		int w = arr[i].second.second;
		if (d[u] != INT_MAX)
		{
			if (d[v] > d[u] + w)
			{
				infinity = true;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	solve();
	if (infinity)
	{
		printf("-1");
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (d[i] == INT_MAX)
			{
				d[i] = -1;
			}
			printf("%d\n", d[i]);
		}
	}

	return 0;
}