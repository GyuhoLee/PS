#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[100], p[20], m[20];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> m[i];
	for (int i = 0; i < N; i++) cin >> p[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 99; j >= m[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - m[i]] + p[i]);
		}
	}
	cout << dp[99];

	return 0;
}