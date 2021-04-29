#include <iostream>
using namespace std;
#define ll long long

int T, N;
ll dp[65][10];

int main()
{
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= 64; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	cin >> T;
	while (T--)
	{
		cin >> N;
		ll ans = 0;
		for (int i = 0; i < 10; i++) ans += dp[N][i];
		cout << ans << '\n';
	}

	return 0;
}