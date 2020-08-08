#include <bits/stdc++.h>
using namespace std;

int N;
int dp[31];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 30; i++) dp[i] = dp[i - 1] + dp[i - 2] * 2; 

	cin >> N;
	int answer = 0;
	if (N % 2) answer = (dp[N] + dp[(N - 1) / 2]) / 2;
	else answer = (dp[N] + dp[N / 2] + dp[(N - 2) / 2] * 2) / 2;
	cout << answer;

	return 0;
}