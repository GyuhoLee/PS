#include <iostream>
using namespace std;


int main() {

	int T;
	cin >> T;
	int N;
	while(T--)
	{
		scanf("%d", &N);
		int dp[41][2] = { 0 };
		dp[0][0] = dp[1][1] = 1;
		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
			dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		}

		printf("%d %d\n", dp[N][0], dp[N][1]);
	}
	return 0;
}