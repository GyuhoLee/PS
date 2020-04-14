#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
#define MOD 1000000000

int N, K;
ll dp[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	cin >> N >> K;
	MS(dp, 0);
	FUP(i, 0, 200) dp[i][1] = 1;
	FUP(j, 2, K)
	{
		FUP(i, 0, N)
		{
			dp[i][j] = 0;
			FUP(k, 0, i)
			{
				dp[i][j] += dp[k][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[N][K];

	return 0;
}