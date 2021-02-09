#include <bits/stdc++.h>
using namespace std;

long long N, M, cnt = 0, p, a, b, t;
vector<pair<int, int>> tip[100001];
long long ans = 0, arr[100001];
bool visited[100001];

int main()
{
	cin >> N >> M;
	priority_queue<pair<long long, long long>> pq;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	cin >> p;
	while (p--)
	{
		cin >> a >> b >> t;
		tip[a].push_back({ b, t });
		arr[b] += t;
	}
	for (int i = 1; i <= N; i++)
	{
		pq.push({ -arr[i], i });
	}
	memset(visited, false, sizeof(visited));
	while (cnt < M)
	{
		long long dis = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (visited[node]) continue;
		ans = max(ans, dis);
		visited[node] = true;
		cnt++;
		for (auto i : tip[node])
		{
			if (!visited[i.first])
			{
				arr[i.first] -= i.second;
				pq.push({ -arr[i.first], i.first });
			}
		}
	}
	cout << ans;


	return 0;
}