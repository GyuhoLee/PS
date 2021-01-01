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

int N, M, dp[51][51][1 << 7], ans = INT_MAX, sy, sx;
char arr[51][51];

struct node
{
	int y, x, bit;
	node() {}
	node(int yy, int xx, int b) : y(yy), x(xx), bit(b) {}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(&dp[0][0][0], &dp[50][50][1 << 7], INT_MAX);
	CIN2(N, M);
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
		{
			CIN(arr[i][j]);
			if (arr[i][j] == '0')
			{
				arr[i][j] = '.';
				sy = i;
				sx = j;
			}
		}
	}
	queue<node> q;
	dp[sy][sx][0] = 0;
	q.push(node(sy, sx, 0));
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int bit = q.front().bit;
		q.pop();
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M || arr[ny][nx] == '#' || dp[ny][nx][bit] != INT_MAX) continue;
			if (arr[ny][nx] == '.')
			{
				dp[ny][nx][bit] = dp[y][x][bit] + 1;
				q.push(node(ny, nx, bit));
			}
			else if (arr[ny][nx] == '1')
			{
				ans = min(dp[y][x][bit] + 1, ans);
				dp[ny][nx][bit] = dp[y][x][bit] + 1;
			}
			else if (arr[ny][nx] >= 'a' && arr[ny][nx] <= 'f')
			{
				int tmp = (1 << (arr[ny][nx] - 'a'));
				dp[ny][nx][bit | tmp] = dp[y][x][bit] + 1;
				q.push(node(ny, nx, bit | tmp));
			}
			else
			{
				if (bit & (1 << (arr[ny][nx] - 'A')))
				{
					dp[ny][nx][bit] = dp[y][x][bit] + 1;
					q.push(node(ny, nx, bit));
				}
			}

		}
	}
	ans == INT_MAX ? COUT(-1) : COUT(ans);

	return 0;
}