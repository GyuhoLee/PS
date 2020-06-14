#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
#define INF  2147483647

ll dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 5;
	dp[3] = 11;
	dp[4] = 36;
	FUP(i, 5, 100)
	{
		dp[i] = dp[i - 1] + dp[i - 2] * 4 + dp[i - 3] * 2 + dp[i - 4] * 3 + dp[i - 5] * 3;
		if (dp[i] > INF) break;
	}
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}