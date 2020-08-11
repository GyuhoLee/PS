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
#define INF 11111111
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int V, E, S;	//V : Node의 수, E : Edge의 수, S : 시작점
int u, v, w;	//u -> v의 가중치 w
vector<pair<int, int>> arr[SIZE], arr2[SIZE];	//	arr[i] = first까지 second의 가중치
int d[SIZE], d2[SIZE]; //시작점에서의 각 idx node 까지의 거리. 처음에 INF값으로 초기화 필요
int answer = 0;

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, S });	// S부터 시작
	d[S] = 0;
	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (distance > d[node]) continue;
		d[node] = distance;
		for (auto iter : arr[node])
		{
			if (d[iter.first] > d[node] + iter.second)
			{
				d[iter.first] = d[node] + iter.second;
				pq.push({ d[iter.first], iter.first });
			}
		}
	} // 끝나고도 d[i]가 INF이면 도달할 수 없음.
}

void dijkstra2()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, S });	// S부터 시작
	d2[S] = 0;
	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (distance > d2[node]) continue;
		d2[node] = distance;
		for (auto iter : arr2[node])
		{
			if (d2[iter.first] > d2[node] + iter.second)
			{
				d2[iter.first] = d2[node] + iter.second;
				pq.push({ d2[iter.first], iter.first });
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
	fill(d2, d2 + SIZE, INF);
	CIN3(V, E, S);
	while (E--)
	{
		CIN3(u, v, w);
		arr[u].push_back({ v, w });
		arr2[v].push_back({ u, w });
	}
	dijkstra();
	dijkstra2();

	FUP(i, 1, V) answer = max(answer, d[i] + d2[i]);
	COUT(answer);

	return 0;
}