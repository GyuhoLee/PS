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
#define SIZE 100
#define INF -1e17
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int V, E, s, e;	//V : Node의 수, E : Edge의 수, S : 시작점
int u, v, w;	//u -> v의 가중치 w
vector<pair<int, ll>> arr[SIZE];	//	arr[i] = first까지 second의 가중치
ll d[SIZE]; //시작점에서의 각 idx node 까지의 거리. 처음에 INF값으로 초기화 필요
ll money[SIZE];
bool visited[SIZE];

void DFS(int node)
{
	visited[node] = true;
	for (auto p : arr[node])
	{
		if (!visited[p.first]) DFS(p.first);
	}
}

bool bellman_ford()
{
	fill(d, d + V + 1, INF);
	d[s] = money[s];
	FUP(repeat, 1, V)
	{
		FUP(i, 0, V - 1)
		{
			if (d[i] == INF) continue;
			for (auto p : arr[i])
			{
				int next = p.first;
				ll dist = p.second;
				if (d[next] < d[i] + dist + money[next])
				{
					d[next] = d[i] + dist + money[next];
					if (repeat == V)
					{
						MS(visited, false);
						DFS(next);
						if (visited[e]) return false;
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(V, s);
	CIN2(e, E);
	while (E--)
	{
		CIN3(u, v, w);
		arr[u].push_back({ v, -w });
	}
	FUP(i, 0, V - 1) CIN(money[i]);
	if (!bellman_ford() && d[e] != INF) COUT("Gee");
	else d[e] != INF ? COUT(d[e]) : COUT("gg");

	return 0;
}