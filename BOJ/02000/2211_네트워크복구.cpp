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
#define INF 1111111111
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int V, E;
int u, v, w;	//u -> v의 가중치 w
vector<pair<int, int>> arr[SIZE];	//	arr[i] = first까지 second의 가중치
int d[SIZE]; //시작점에서의 각 idx node 까지의 거리. 처음에 INF값으로 초기화 필요

void dijkstra()
{
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, {1, -1 } });	// S부터 시작
	d[1] = 0;
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int node = pq.top().second.first;
		int before = pq.top().second.second;
		pq.pop();
		if (distance > d[node]) continue;
		if (before != -1)
		{
			COUT2(node, before);
			ENDL;
		}
		d[node] = distance;
		for (auto iter : arr[node])
		{
			if (d[iter.first] > d[node] + iter.second)
			{
				d[iter.first] = d[node] + iter.second;
				pq.push({ -d[iter.first], {iter.first, node } });
			}
		}
	} // 끝나고도 d[i]가 INF이면 도달할 수 없음.
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(d, d + SIZE, INF);
	CIN2(V, E);
	while (E--)
	{
		CIN3(u, v, w);
		arr[u].push_back({ v, w });
		arr[v].push_back({ u, w });
	}
	COUT(V - 1);
	ENDL;
	dijkstra();

	return 0;
}