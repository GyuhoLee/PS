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

int N, M, K, arr[101][101], ans = 0, cnt;
bool visited[101][101];

void DFS(int y, int x)
{
	visited[y][x] = true;
	cnt++;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!arr[ny][nx] || visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, 0);
	MS(visited, false);
	CIN3(N, M, K);
	while (K--)
	{
		int r, c;
		CIN2(r, c);
		arr[r][c] = 1;
	}
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
		{
			if (!arr[i][j] || visited[i][j]) continue;
			cnt = 0;
			DFS(i, j);
			ans = max(ans, cnt);
		}
	}
	COUT(ans);

	return 0;
}