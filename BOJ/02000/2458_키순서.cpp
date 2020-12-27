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

int a, b, N, M, ans = 0;
bool visited[501], sv[501], bv[501];
vector<int> small[501], big[501];

void sDFS(int now)
{
	visited[now] = true;
	sv[now] = true;
	for (int next : small[now])
	{
		if(!sv[next]) sDFS(next);
	}
}

void bDFS(int now)
{
	visited[now] = true;
	bv[now] = true;
	for (int next : big[now])
	{
		if(!bv[next]) bDFS(next);
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
		big[a].push_back(b);
		small[b].push_back(a);
	}
	FUP(i, 1, N)
	{
		MS(visited, false);
		MS(sv, false);
		MS(bv, false);
		sDFS(i);
		bDFS(i);
		FUP(j, 1, N)
		{
			if (!visited[j]) break;
			if (j == N) ans++;
		}
	}
	COUT(ans);

	return 0;
}