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

int T, N, M, match[1001], a, b, ans = 0;
bool visited[1001];
vector<int> edge[1001];

int DFS(int node)
{
	if (visited[node]) return 0;
	visited[node] = true;
	for (int next : edge[node])
	{
		if (!match[next] || DFS(match[next]))
		{
			match[next] = node;
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		MS(match, 0);
		ans = 0;
		CIN2(M, N);
		FUP(i, 1, N)
		{
			edge[i].clear();
			CIN2(a, b);
			FUP(j, a, b)
			{
				edge[i].push_back(j);
			}
		}
		FUP(i, 1, N)
		{
			MS(visited, false);
			ans += DFS(i);
		}
		COUT(ans);
		ENDL;
	}
	return 0;
}