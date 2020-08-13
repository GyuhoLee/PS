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
#define SIZE 1001
#define INF 1e15
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int V, E;
int u, v, w;	//u -> v의 가중치 w
vector<pair<int, ll>> arr[SIZE];	//	arr[i] = first까지 second의 가중치
ll d[SIZE]; //시작점에서의 각 idx node 까지의 거리. 처음에 INF값으로 초기화 필요
ll out[SIZE];
int pre[SIZE];

void print(int num)
{
	if (pre[num] != 1) print(pre[num]);
	COUT2("", num);
}

void bellman_ford()
{
	fill(d, d + V + 1, INF);
	d[1] = 0;
	pre[1] = 0;
	FUP(repeat, 1, V)
	{
		FUP(i, 1, V)
		{
			if (d[i] == INF) continue;
			for (auto p : arr[i])
			{
				int next = p.first;
				ll dist = p.second;
				if (d[next] > d[i] + dist)
				{
					d[next] = d[i] + dist;
					pre[next] = i;
					if (repeat == V && out[next] != INF)
					{
						COUT(-1);
						return;
					}
				}
			}
		}
	}
	COUT(1);
	print(V);
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(V, E);
	fill(out, out + V + 1, INF);
	while (E--)
	{
		CIN3(u, v, w);
		if (v == V) out[u] = -w;
		arr[u].push_back({ v, -w });
	}
	bellman_ford();

	return 0;
}