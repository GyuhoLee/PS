#include <bits/stdc++.h>
using namespace std;

int N, W;
pair<int, int> arr[1001];
int dp[1001][1001];

int distance(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int first, int second)
{
	if (first == W || second == W) return 0;
	if (dp[first][second] != -1) return dp[first][second];
	int next = max(first, second) + 1;
	int dist1, dist2;

	if (first == 0) dist1 = distance(arr[next - 1], { 1, 1 });
	else dist1 = distance(arr[next - 1], arr[first - 1]);

	if (second == 0) dist2 = distance(arr[next - 1], { N, N });
	else dist2 = distance(arr[next - 1], arr[second - 1]);


	int left = solve(next, second) + dist1;
	int right = solve(first, next) + dist2;

	dp[first][second] = min(left, right);

	return dp[first][second];
}

void back(int first, int second) {

	if (first == W || second == W) {
		return;
	}

	int next = max(first, second) + 1;
	int dist1, dist2;

	if (first == 0) dist1 = distance(arr[next - 1], { 1, 1 });
	else dist1 = distance(arr[next - 1], arr[first - 1]);

	if (second == 0) dist2 = distance(arr[next - 1], { N, N });
	else dist2 = distance(arr[next - 1], arr[second - 1]);


	if (dp[next][second] + dist1 > dp[first][next] + dist2) {
		cout << 2 << '\n';
		back(first, next);
	}
	else {
		cout << 1 << '\n';
		back(next, second);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> N >> W;
	for (int i = 0; i < W; i++) cin >> arr[i].first >> arr[i].second;
	cout << solve(0, 0) << '\n';
	back(0, 0);

	return 0;
}