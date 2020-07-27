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
#define MOD 1000000007

vector<pair<int, int>> v[100001];
int N, a, b, c;
ll answer = 0;

ll DFS(ll now, ll before)
{
	ll num = 1, temp;
	FUP(i, 0, v[now].size() - 1)
	{
		ll node = v[now][i].first;
		if (node == before) continue;
		temp = DFS(node, now) * v[now][i].second % MOD;
		answer = (answer + temp * num) % MOD;
		num = (temp + num) % MOD;
	}
	return num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N - 1)
	{
		CIN3(a, b, c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	DFS(1, 0);
	COUT(answer);

	return 0;
}