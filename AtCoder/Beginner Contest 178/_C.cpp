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

ll dp[1000001];
ll eight[1000001];
ll one[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	eight[0] = 1;
	one[1] = 1;
	FUP(i, 1, 1000000)
	{
		eight[i] = eight[i - 1] * 8 % MOD;
		one[i] = one[i - 1] * 9 + eight[i - 1];
		one[i] %= MOD;
	}
	dp[1] = 0;
	dp[2] = 2;
	FUP(i, 3, 1000000)
	{
		dp[i] = dp[i - 1] * 10 % MOD + 1LL * 2 * one[i - 1] % MOD;
		dp[i] %= MOD;
	}
	int N;
	CIN(N);
	COUT(dp[N]);

	return 0;
}