#include <iostream>
#include <algorithm>
using namespace std;

int T, N, arr[1000], dp[1000], ans;

int main()
{
	cin >> T;
	while (T--)
	{
		ans = -2e9;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			if (!i) dp[i] = arr[i];
			else dp[i] = max(arr[i], dp[i - 1] + arr[i]);
			ans = max(ans, dp[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}