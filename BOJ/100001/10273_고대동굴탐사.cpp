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
const int MAX = 20001;

int T, N, E;
int arr[MAX], dp[MAX], track[MAX];
vector<int> answer;
vector<pair<int, int>> v[MAX];

int topology_sort(int now)
{
	if (dp[now] != 0) return dp[now];
	for (auto p : v[now])
	{
		int num = topology_sort(p.first) - p.second;
		if (num > dp[now])
		{
			dp[now] = num;
			track[now] = p.first;
		}
	}
	dp[now] += arr[now];
	return dp[now];
}

void DFS(int node)
{
	answer.push_back(node);
	if (track[node] == -1) return;
	DFS(track[node]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		CIN2(N, E);
		answer.clear();
		MS(dp, 0);
		MS(track, -1);
		FUP(i, 1, N)
		{
			CIN(arr[i]);
			v[i].clear();
		}
		while (E--)
		{
			int a, b, c;
			CIN3(a, b, c);
			v[a].push_back({ b, c });
		}
		int num = topology_sort(1);
		DFS(1);
		COUT2(num, answer.size());
		ENDL;
		for (int i : answer) COUT2(i, "");
		ENDL;
	}

	return 0;
}