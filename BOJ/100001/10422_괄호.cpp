#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long int dp[5001];

void DP()
{
	dp[1] = 1;
	dp[2] = 0;
	for (int i = 4; i <= 5000; i += 2)
	{
		dp[i - 1] = (dp[i - 2] + dp[i - 3]) % MOD;
		dp[i] = 0;
		for (int j = 2; j < i; j += 2)
		{
			dp[i] = (dp[i] + dp[j - 1] * (dp[i - j] + dp[i - j - 1])) % MOD;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	DP();
	int T;
	cin >> T;
	while (T--)
	{
		int L;
		cin >> L;
		if (L % 2)
		{
			cout << "0\n";
			continue;
		}
		else cout << (dp[L] + dp[L - 1]) % MOD << '\n';
	}

	return 0;
}