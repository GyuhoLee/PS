#include <bits/stdc++.h>
using namespace std;
#define INF 111111111

int N, P;
int arr[16][16];
int dp[1 << 16];
int first = 0;

void input()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	string str;
	cin >> str;
	int i = 1;
	for (auto s : str)
	{
		if (s == 'Y')
		{
			first += i;
		}
		i <<= 1;
	}
	cin >> P;
}

int bitCount(int n)
{
	if (n == 0) return 0;
	else return n % 2 + bitCount(n / 2);
}

int solve(int before)
{
	if (dp[before] != -1) return dp[before];
	if (bitCount(before) >= P) return 0;
	dp[before] = INF;
	for (int i = 0; i < N; i++) {
		if (!(before & (1 << i))) continue;
		for (int j = 0; j < N; j++)
		{
			if ((before & (1 << j))) continue;
			int temp = solve((1 << j) | before) + arr[i][j];
			if (temp < dp[before]) dp[before] = temp;
		}
	}
	return dp[before];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	int cnt = bitCount(first);
	if (cnt >= P)
	{
		cout << 0;
		return 0;
	}
	if (!cnt)
	{
		cout << -1;
		return 0;
	}

	int answer = solve(first);
	if (answer >= INF) answer = -1;
	cout << answer;

	return 0;
}