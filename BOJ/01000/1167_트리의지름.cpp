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
#define INF 987654321

int N, a, b, c, d[100001], ans = 0, node = 0;
vector<pair<int, int>> v[100001];

void DFS(int now)
{
	if (d[now] > ans)
	{
		ans = d[now];
		node = now;
	}
	for (auto p : v[now])
	{
		if (d[now] + p.second < d[p.first])
		{
			d[p.first] = d[now] + p.second;
			DFS(p.first);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N)
	{
		d[i] = INF;
		CIN(a);
		while (true)
		{
			CIN(b);
			if (b == -1) break;
			CIN(c);
			v[a].push_back({ b, c });
		}
	}

	d[1] = 0;
	DFS(1);
	FUP(i, 1, N) d[i] = INF;
	d[node] = 0;
	DFS(node);
	COUT(ans);

	return 0;
}