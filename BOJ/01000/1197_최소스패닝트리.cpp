#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int V, E, answer = 0;
int u, v, w;
vector<pair<int, int>> arr[10001];
bool visited[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(V, E);
	while (E--)
	{
		CIN3(u, v, w);
		arr[u].push_back({ v, w });
		arr[v].push_back({ u, w });
	}
	for (auto p : arr[1])
	{
		pq.push({ p.second, p.first });
	}
	visited[1] = true;
	int cnt = 1;
	while (!pq.empty())
	{
		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (visited[node]) continue;
		if (++cnt > V) break;
		answer += dis;
		visited[node] = true;
		for (auto p : arr[node])
		{
			if (!visited[p.first]) pq.push({ p.second, p.first });
		}
	}
	COUT(answer);

	return 0;
}