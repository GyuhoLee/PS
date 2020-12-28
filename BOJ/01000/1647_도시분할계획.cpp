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

int N, M, ans = 0, big = 0, a, b, c;
vector<pair<int, int>> edge[100001];
bool visited[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(visited, false);
	CIN2(N, M);
	while (M--)
	{
		CIN3(a, b, c);
		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	visited[1] = true;
	for (auto p : edge[1])
	{
		pq.push(p);
	}
	while(!pq.empty())
	{
		int node = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if (visited[node]) continue;
		visited[node] = true;
		ans += dist;
		big = max(big, dist);
		for (auto p : edge[node])
		{
			if (visited[p.second]) continue;
			pq.push(p);
		}
	}
	COUT(ans - big);



	return 0;
}