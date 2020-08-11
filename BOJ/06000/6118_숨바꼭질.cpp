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
#define SIZE 20001
#define INF 11111111
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int V, E;
int u, v;
vector<int> arr[SIZE];
int d[SIZE];

void BFS()
{
	queue<int> q;
	q.push(1);
	d[1] = 0;
	int Last = 1;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int iter : arr[node])
		{
			if (d[iter] != -1) continue;
			d[iter] = d[node] + 1;
			q.push(iter);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(d, -1);
	CIN2(V, E);
	while (E--)
	{
		CIN2(u, v);
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	BFS();

	int max_num = 0, max_idx = 1, max_cnt = 1;
	FUP(i, 2, V)
	{
		if (max_num < d[i])
		{
			max_num = d[i];
			max_idx = i;
			max_cnt = 1;
		}
		else if (max_num == d[i]) max_cnt++;
	}

	COUT3(max_idx, max_num, max_cnt);

	return 0;
}