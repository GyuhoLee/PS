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
#define SIZE 5001
#define INF 987654321
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
int a, b, c, D;
int d[SIZE], in[SIZE], out[SIZE];
int answer = INF;
vector<pair<int, int>> arr[SIZE];
vector<int> one;

void dijkstra(int bit, bool ok)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (auto x : one)
	{
		if ((x & (1 << bit)) == ok)
		{
			pq.push({ in[x], x });
			d[x] = in[x];
		}
	}
	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (distance > d[node]) continue;
		for (auto iter : arr[node])
		{
			if (d[iter.first] > d[node] + iter.second)
			{
				d[iter.first] = d[node] + iter.second;
				pq.push({ d[iter.first], iter.first });
			}
		}
	}
	for (auto x : one)
	{
		if (d[x] != in[x])
		{
			answer = min(answer, out[x] + d[x]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	while (M--)
	{
		CIN2(a, b);
		CIN2(c, D);
		if (a == 1)
		{
			one.push_back(b);
			in[b] = c;
			out[b] = D;
		}
		else if (b == 1)
		{
			one.push_back(a);
			in[a] = D;
			out[a] = c;
		}
		else
		{
			arr[a].push_back({ b, c });
			arr[b].push_back({ a, D });
		}
	}
	FUP(i, 0, 12)
	{
		fill(d, d + SIZE, INF);
		dijkstra(i, true);
		fill(d, d + SIZE, INF);
		dijkstra(i, false);
	}

	COUT(answer);

	return 0;
}