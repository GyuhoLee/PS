#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[1] = dp[3] = dp[4] = 1;
	dp[2] = 2;
	for (int i = 5; i <= 1000; i++)
	{
		if (dp[i - 1] == 2 || dp[i - 3] == 2 || dp[i - 4] == 2) dp[i] = 1;
		else dp[i] = 2;
	}
	int N;
	cin >> N;
	if (dp[N] == 1) cout << "SK";
	else cout << "CY";

	return 0;
}