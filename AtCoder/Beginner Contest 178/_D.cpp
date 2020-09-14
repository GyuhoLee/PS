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

ll dp[2001];
ll sum[2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[0] = dp[1] = dp[2] = 0;
	sum[0] = sum[1] = sum[2] = 0;
	FUP(i, 3, 2000)
	{
		dp[i] = 1 + sum[i - 3];
		dp[i] %= MOD;
		sum[i] = sum[i - 1] + dp[i];
		sum[i] %= MOD;
	}
	int N;
	CIN(N);
	COUT(dp[N]);



	return 0;
}