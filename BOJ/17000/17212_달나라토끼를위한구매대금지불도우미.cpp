#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main()
{
	int N;
	cin >> N;
	int num[4] = { 1, 2, 5, 7 };
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1e9;
		for (int tmp : num)
		{
			if (i >= tmp) dp[i] = min(dp[i], dp[i - tmp] + 1);
		}
	}
	cout << dp[N];

	return 0;
}