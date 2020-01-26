#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M, K;
long long int dp[102][102];
string answer;

void input()
{
	cin >> N >> M >> K;
	dp[0][0] = 0;
	dp[1][1] = 2;
	for (int i = 1; i <= 100; i++)
	{
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			dp[i + 1][j] = dp[i][j] * (i + j + 1) / (i + 1);
			dp[i][j + 1] = dp[i][j] * (i + j + 1) / (j + 1);
			if (dp[i + 1][j] > 1000000000) dp[i + 1][j] = 1000000001;
			if (dp[i][j + 1] > 1000000000) dp[i][j + 1] = 1000000001;
		}
	}
}

void solve(int cnt, int a, int z)
{
	if (!a)
	{
		while (z--)
		{
			answer += 'z';
		}
		return;
	}
	if (!z)
	{
		while (a--)
		{
			answer += 'a';
		}
		return;
	}

	if (dp[a - 1][z] >= cnt)
	{
		answer += 'a';
		solve(cnt, a - 1, z);
	}
	else
	{
		answer += 'z';
		solve(cnt - dp[a - 1][z], a, z - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	if (dp[N][M] < K) answer = "-1";
	else solve(K, N, M);
	cout << answer;

	return 0;
}