#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[100001], dp[100001][2], ans = -10000;

int main()
{
	dp[0][0] = dp[0][1] = -10000;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i][0] = max(dp[i - 1][0], 0) + arr[i];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		ans = max({ dp[i][0], dp[i][1], ans });
	}
	cout << ans;

	return 0;
}