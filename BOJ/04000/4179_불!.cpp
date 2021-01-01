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

int R, C, arr[1001][1001], dp[1001][1001], ans = INT_MAX, fy, fx;
char ch;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int, int>> q;
	CIN2(R, C);
	FUP(i, 1, R)
	{
		FUP(j, 1, C)
		{
			dp[i][j] = INT_MAX;
			CIN(ch);
			switch (ch)
			{
			case '#': arr[i][j] = -1; break;
			case 'J': fy = i; fx = j;
			case '.': arr[i][j] = INT_MAX; break;
			case 'F': arr[i][j] = 0; q.push({ i, j });
			}
		}
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > R || nx > C || arr[ny][nx] == -1 || arr[ny][nx] != INT_MAX) continue;
			arr[ny][nx] = arr[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	q.push({ fy, fx });
	dp[fy][fx] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > R || nx > C)
			{
				ans = min(ans, dp[y][x] + 1);
				continue;
			}
			if (arr[ny][nx] == -1 || arr[ny][nx] <= dp[y][x] + 1 || dp[ny][nx] != INT_MAX) continue;
			dp[ny][nx] = dp[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	ans == INT_MAX ? COUT("IMPOSSIBLE") : COUT(ans);

	return 0;
}