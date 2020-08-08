#include <iostream>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
int u, v, w;
vector<pair<int, int>> arr[20001];
int d[20001];

void input()
{
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		arr[u].push_back(make_pair(v, w));
	}
	fill(d, d + 20001, INT_MAX);
}

void solve()
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, K));
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (distance > d[node]) continue;
		d[node] = distance;
		for (auto iter : arr[node])
		{
			if (d[iter.first] > d[node] + iter.second)
			{
				d[iter.first] = d[node] + iter.second;
				pq.push(make_pair(-d[iter.first], iter.first));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INT_MAX) cout << "INF\n";
		else cout << d[i] << '\n';
	}
}

int main()
{
	input();
	solve();

	return 0;
}