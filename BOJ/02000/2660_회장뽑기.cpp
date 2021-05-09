#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, ans = 100, a, b;
bool visited[51];
vector<int> edge[51], v;

void Clear()
{
	for (int i = 1; i <= N; i++) visited[i] = false;
}

int main()
{
	cin >> N;
	while (true)
	{
		cin >> a >> b;
		if (a == -1) break;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		Clear();
		queue<pair<int, int>> q;
		q.push({i, 0});
		visited[i] = true;
		int tmp = 0;
		while (!q.empty())
		{
			int idx = q.front().first;
			int dist = q.front().second;
			q.pop();
			tmp = max(tmp, dist);
			for (int next : edge[idx])
			{
				if (visited[next]) continue;
				visited[next] = true;
				q.push({ next, dist + 1 });
			}
		}
		if (tmp < ans)
		{
			v.clear();
			v.push_back(i);
			ans = tmp;
		}
		else if (tmp == ans) v.push_back(i);
	}
	cout << ans << ' ' << v.size() << '\n';
	for (int num : v)
	{
		cout << num << ' ';
	}

	return 0;
}