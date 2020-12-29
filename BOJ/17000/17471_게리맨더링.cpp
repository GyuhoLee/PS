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

int N, M, arr[10], ans = 10000, team[10], num[2];
vector<int> edge[10];
bool visited[10];

void DFS(int node)
{
	num[team[node]] += arr[node];
	visited[node] = true;
	if (edge[node].size() == 0) return;
	for (int next : edge[node])
	{
		if (visited[next] || team[node] != team[next]) continue;
		DFS(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1)
	{
		CIN(arr[i]);
	}
	FUP(i, 0, N - 1)
	{
		CIN(M);
		while (M--)
		{
			int tmp;
			CIN(tmp);
			edge[i].push_back(tmp - 1);
		}
	}
	FUP(bit, 1, pow(2, N) - 1)
	{
		MS(visited, false);
		num[0] = num[1] = 0;
		FUP(i, 0, N - 1) team[i] = (bool)((1 << i) & bit);
		FUP(i, 0, N - 1)
		{
			if (num[team[i]]) continue;
			DFS(i);
		}
		FUP(i, 0, N - 1)
		{
			if (!visited[i]) break;
			if (i == N - 1) ans = min(ans, abs(num[0] - num[1]));
		}
	}
	COUT((ans == 10000 ? -1 : ans));

	return 0;
}