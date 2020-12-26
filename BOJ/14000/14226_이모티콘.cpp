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

int dp[1001][1001], ans = 987654321, S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(S);
	fill(&dp[0][0], &dp[1000][1001], INT_MAX);
	dp[1][0] = 0;
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	while (!q.empty())
	{
		int num = q.front().first;
		int board = q.front().second;
		int cnt = dp[num][board];
		q.pop();
		if (num >= S)
		{
			ans = min(num - S + dp[num][board], ans);
			continue;
		}

		if (num && cnt + 1 < dp[num - 1][board])
		{
			dp[num - 1][board] = cnt + 1;
			q.push({ num - 1, board });
		}
		if (num && cnt + 2 < dp[num - 1][num])
		{
			dp[num - 1][num] = cnt + 2;
			q.push({ num - 1, num });
		}
		if (board)
		{
			if (num + board > 1000)
			{
				ans = min(cnt + 1 + num + board - S, ans);
			}
			else if(dp[num + board][board] > cnt + 1)
			{
				dp[num + board][board] = cnt + 1;
				q.push({ num + board, board });
			}
		}
		if (num * 2 > 1000)
		{
			ans = min(cnt + 2 + num + num - S, ans);
		}
		else if (dp[num * 2][num] > cnt + 2)
		{
			dp[num * 2][num] = cnt + 2;
			q.push({ num * 2, num });
		}

	}
	COUT(ans);

	return 0;
}