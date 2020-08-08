#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int X, Y, W;
int arr[1001];
int dp[1001];
bool visited[1001];
multimap<int, int> M;

void input()
{
	M.clear();
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i] = 0;
		visited[i] = false;
	}
	while (K--)
	{
		cin >> X >> Y;
		M.insert({ Y, X });
	}
	cin >> W;
}

int solve(int num)
{
	if (visited[num]) return dp[num];
	visited[num] = true;
	if (dp[num]) return dp[num];
	if (!M.count(num))
	{
		dp[num] = arr[num];
		return dp[num];
	}
	int temp = 0;
	auto iter_pair = M.equal_range(num);
	for (auto iter = iter_pair.first; iter != iter_pair.second; iter++)
	{
		temp = max(temp, solve(iter->second));
	}
	dp[num] = temp + arr[num];
	return dp[num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		input();
		cout << solve(W) << '\n';
	}

	return 0;
}