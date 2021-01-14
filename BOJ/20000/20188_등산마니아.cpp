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
const int MAX = 300001;

bool visited[MAX];
pair<int, int> edge[MAX - 1];
vector<int> tree[MAX];
ll N, ans = 0, child[MAX];

int DFS(int node)
{
	child[node] = 1;
	visited[node] = true;
	for (int next : tree[node])
	{
		if (visited[next]) continue;
		child[node] += DFS(next);
	}
	return child[node];
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(child, 0);
	MS(visited, false);
	CIN(N);
	FUP(i, 1, N - 1)
	{
		int a, b;
		CIN2(a, b);
		tree[a].push_back(b);
		tree[b].push_back(a);
		edge[i] = { a, b };
	}
	DFS(1);
	FUP(i, 1, N - 1)
	{
		int p = edge[i].first, c = edge[i].second;
		if (child[p] < child[c]) swap(c, p);
		ans += (N * (N - 1) / 2);
		ll M = N - child[c];
		ans -= (M * (M - 1) / 2);
	}
	COUT(ans);

	return 0;
}