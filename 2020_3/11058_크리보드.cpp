#include <bits/stdc++.h>
using namespace std;

int N;
long long int dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 4; i++) dp[i] = i;
	for (int i = 5; i <= 100; i++)
	{
		dp[i] = max(dp[i - 1] + 1, dp[i - 3] * 2);
		for (int j = 4; i - j > 0; j++)
		{
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}
	}
	int N;
	cin >> N;
	cout << dp[N];

	return 0;
}