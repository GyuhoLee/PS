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
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int N, M, x, y, d, ex, ey, ed, arr[101][101], dp[101][101][4];

struct node
{
	int x, y, d;
	node() {}
	node(int yy, int xx, int dd) : x(xx), y(yy), d(dd) {}
	
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	fill(&dp[0][0][0], &dp[100][100][4], INT_MAX);
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
		{
			CIN(arr[i][j]);
		}
	}
	CIN3(y, x, d); d--;
	CIN3(ey, ex, ed); ed--;
	queue<pair<int, node>> q;
	q.push({ 0, node(y, x, d) });
	dp[y][x][d] = 0;
	while (!q.empty())
	{
		int dis = q.front().first;
		int y = q.front().second.y;
		int x = q.front().second.x;
		int d = q.front().second.d;
		q.pop();
		if (dp[y][x][d] < dis) continue;
		FUP(i, 1, 3)
		{
			int ny = y + (i * dy[d]);
			int nx = x + (i * dx[d]);
			if (ny < 1 || nx < 1 || ny > N || nx > M || arr[ny][nx]) break;
			if (dp[ny][nx][d] > dis + 1)
			{
				dp[ny][nx][d] = dis + 1;
				q.push({ dp[ny][nx][d], node(ny, nx, d) });
			}
		}
		int fd = d;
		int tmp = 1;
		d = (d + 1) % 4;
		if ((d + fd) % 4 == 1) tmp = 2;
		if (dp[y][x][d] > dis + tmp)
		{
			dp[y][x][d] = dis + tmp;
			q.push({ dp[y][x][d], node(y, x, d) });
		}
		d = (d + 1) % 4;
		tmp = 1;
		if (dp[y][x][d] > dis + 1)
		{
			dp[y][x][d] = dis + 1;
			q.push({ dp[y][x][d], node(y, x, d) });
		}
		d = (d + 1) % 4;
		if ((d + fd) % 4 == 1) tmp = 2;
		if (dp[y][x][d] > dis + tmp)
		{
			dp[y][x][d] = dis + tmp;
			q.push({ dp[y][x][d], node(y, x, d) });
		}
	}
	COUT(dp[ey][ex][ed]);

	return 0;
}