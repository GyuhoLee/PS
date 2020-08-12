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
#define SIZE 2001
#define INF 1111111111
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int V, E, t, s, g, h;
int u, v, w;
vector<pair<int, int>> arr[SIZE];
int d[SIZE];
bool ok[SIZE];
set<int> object;

void dijkstra()
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {s, -1} });
	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second.first;
		int before = pq.top().second.second;
		pq.pop();
		if (distance > d[node]) continue;
		d[node] = distance;
		if(!ok[node]) ok[node] = ok[before];
		if ((before == g && node == h) || (before == h && node == g)) ok[node] = true;
		for (auto iter : arr[node])
		{
			if (d[iter.first] > d[node] + iter.second)
			{
				d[iter.first] = d[node] + iter.second;
				pq.push({ d[iter.first], {iter.first, node} });
			}
			else if (d[iter.first] == d[node] + iter.second)
			{
				if (!ok[iter.first]) ok[iter.first] = ok[node];
				if ((iter.first == g && node == h) || (iter.first == h && node == g)) ok[iter.first] = true;
			}
		}
	} 
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
		CIN3(V, E, t);
		CIN3(s, g, h);
		object.clear();
		FUP(i, 1, V)
		{
			arr[i].clear();
			d[i] = INF;
			ok[i] = false;
		}
		while (E--)
		{
			CIN3(u, v, w);
			arr[u].push_back({ v, w });
			arr[v].push_back({ u, w });
		}
		while(t--)
		{
			int num;
			CIN(num);
			object.insert(num);
		}
		dijkstra();
		for (auto num : object)
		{
			if (ok[num]) COUT2(num, "");
		}
		ENDL;
	}

	return 0;
}