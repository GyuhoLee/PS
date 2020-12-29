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

int a, b, N, M, S;
int visited[501];
vector<int> small[501], big[501];

void sDFS(int now)
{
	visited[now] = 1;
	for (int next : small[now])
	{
		if (!visited[next]) sDFS(next);
	}
}

void bDFS(int now)
{
	visited[now] = -1;
	for (int next : big[now])
	{
		if (!visited[next]) bDFS(next);
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
	CIN(S);
	while(S--)
	{
		CIN2(a, b);
		MS(visited, 0);
		sDFS(a);
		bDFS(a);
		COUT(visited[b]);
		ENDL;
	}

	return 0;
}