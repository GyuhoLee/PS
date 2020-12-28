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

int N, M, a, b, c, s, e;
bool visited[100001];
vector<pair<int, int>> edge[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	while (M--)
	{
		CIN3(a, b, c);
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
	CIN2(s, e);
	priority_queue<pair<int, int>> pq;
	pq.push({ 1000000000, s });
	MS(visited, false);
	while (!pq.empty())
	{
		int mg = pq.top().first;
		int node = pq.top().second;
		if (node == e)
		{
			COUT(mg);
			break;
		}
		pq.pop();
		if (visited[node]) continue;
		visited[node] = true;
		for (auto p : edge[node])
		{
			int next = p.first;
			int nextMG = min(mg, p.second);
			if (visited[next]) continue;
			pq.push({ nextMG, next });
		}
	}


	return 0;
}