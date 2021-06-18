#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, X, a, b, dist[1000001];
vector<int> ans, edge[1000001];

int main()
{
	cin >> N >> M >> K >> X;
	while (M--)
	{
		cin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) dist[i] = -1;
	dist[X] = 0;
	queue<int> q;
	q.push(X);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (dist[node] == K) ans.push_back(node);
		for (int next : edge[node])
		{
			if (dist[next] != -1) continue;
			dist[next] = dist[node] + 1;
			q.push(next);
		}
	}
	if (ans.empty()) cout << -1;
	else
	{
		sort(ans.begin(), ans.end());
		for (int a : ans) cout << a << '\n';
	}

	return 0;
}