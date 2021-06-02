#include <iostream>
#include <map>
#include <queue>
using namespace std;

int N, M, dist[101], a, b;
map<int, int> table;

int main()
{
	for (int i = 1; i <= 100; i++) dist[i] = 10000;
	cin >> N >> M;
	N += M;
	while (N--)
	{
		cin >> a >> b;
		table[a] = b;
	}
	priority_queue<pair<int, int>> pq;
	dist[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		int d = -pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		if (idx == 100) break;
		if (dist[idx] < d) continue;
		for (int i = 1; i <= 6 && idx + i <= 100; i++)
		{
			int next = idx + i;
			if (table.count(next)) next = table[next];
			if (dist[next] <= d + 1) continue;
			dist[next] = d + 1;
			pq.push({ -dist[next], next });
		}
	}
	cout << dist[100];

	return 0;
}