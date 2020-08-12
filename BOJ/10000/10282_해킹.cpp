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

int N, D, C, answer, answer_cnt;
vector<pair<int, int>> arr[10001];
int d[10001];
int u, v, w;

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, C });
	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (distance > d[node]) continue;
		answer = max(answer, distance);
		answer_cnt++;
		d[node] = distance;
		for (auto iter : arr[node])
		{
			if (d[iter.first] > d[node] + iter.second)
			{
				d[iter.first] = d[node] + iter.second;
				pq.push({ d[iter.first], iter.first });
			}
		}
	}
	COUT2(answer_cnt, answer);
	ENDL;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	CIN(T);
	while (T--)
	{
		CIN3(N, D, C);
		FUP(i, 1, N)
		{
			arr[i].clear();
			d[i] = 1111111111;
		}
		answer = answer_cnt = 0;
		while (D--)
		{
			CIN3(u, v, w);
			arr[v].push_back({ u, w });
		}
		dijkstra();
	}

	return 0;
}