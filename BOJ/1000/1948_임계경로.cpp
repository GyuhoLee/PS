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

int N, M, d[10001];
bool visited[10001];
vector<pair<int, int>> v[10001];
int S, E, cnt = 0;

int DFS(int num)
{
	if (d[num] != -1) return d[num];
	for (auto p : v[num])
	{
		d[num] = max(d[num], DFS(p.first) + p.second);
	}
	return d[num];
}

void DFS2(int num)
{
	if (num == E || visited[num]) return;
	visited[num] = true;
	for (auto p : v[num])
	{
		if (d[p.first] + p.second == d[num])
		{
			cnt++;
			DFS2(p.first);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(d, -1);
	MS(visited, false);
	CIN2(N, M);
	while (M--)
	{
		int a, b, c;
		CIN3(a, b, c);
		v[a].push_back({ b, c });
	}
	CIN2(S, E);

	d[E] = 0;
	DFS(S);
	COUT(d[S]);
	ENDL;
	DFS2(S);
	COUT(cnt);

	return 0;
}