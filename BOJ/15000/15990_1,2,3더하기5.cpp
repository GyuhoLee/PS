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

#define MOD 1000000009
ll T, N, dp[100001][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(dp, 0);
	dp[1][1] = dp[2][2] = dp[3][3] = dp[3][1] = dp[3][2] = 1;
	FUP(i, 4, 100000)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}
	CIN(T);
	while (T--)
	{
		CIN(N);
		COUT((dp[N][1] + dp[N][2] + dp[N][3]) % MOD);
		ENDL;
	}

	return 0;
}