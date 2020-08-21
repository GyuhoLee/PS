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
#define MOD 1000000

string str;
int dp[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(str);
	str = '0' + str;
	dp[0] = 1;
	dp[1] = 1;
	if (str[1] == '0')
	{
		COUT(0);
		return 0;
	}
	FUP(i, 2, str.length() - 1)
	{
		dp[i] = dp[i - 1];
		if (str[i] == '0') 
		{
			if (str[i - 1] != '1' && str[i - 1] != '2')
			{
				COUT(0);
				return 0;
			}
			dp[i] = dp[i - 2];
		}
		else if (str[i - 1] == '1') dp[i] += dp[i - 2];
		else if (str[i - 1] == '2' && str[i] <= '6') dp[i] += dp[i - 2];
		dp[i] %= MOD;
	}
	COUT(dp[str.length() - 1]);

	return 0;
}