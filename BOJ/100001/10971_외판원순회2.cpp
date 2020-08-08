#include <bits/stdc++.h>
using namespace std;
#define INF 111111111

int N;
int arr[16][16];
int dp[16][1 << 16];
int answer = INT_MAX;

void input()
{
	memset(dp[0], 0, sizeof(dp[0]));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
}

int solve(int node, int before)
{
	if (dp[node][before]) return dp[node][before];
	if (before == (1 << N) - 1)
	{
		if (arr[node][0]) return arr[node][0];
		else return INF;
	}

	dp[node][before] = INF;
	for (int i = 0; i < N; i++) {
		if (before & 1 << i || !arr[node][i]) continue;
		int temp = solve(i, (before | 1 << i)) + arr[node][i];
		if (temp < dp[node][before]) dp[node][before] = temp;
	}

	return dp[node][before];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve(0, 1);
	cout << dp[0][1];

	return 0;
}