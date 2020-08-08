#include <bits/stdc++.h>
using namespace std;

int N;
int SCV[3] = { 0, 0, 0 };
int answer = INT_MAX;
int dp[61][61][61];
bool visited[61][61][61];

int attack(int a, int b, int c)
{
	int arr[3] = { a, b, c };
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] < 0) arr[i] = 0;
	}
	a = arr[2];
	b = arr[1];
	c = arr[0];
	if (visited[a][b][c]) return dp[a][b][c];
	visited[a][b][c] = true;
	if (a <= 0 && b <= 0 && c <= 0) return 0;
	dp[a][b][c] = attack(a - 9, b - 3, c - 1) + 1;
	dp[a][b][c] = min(attack(a - 9, b - 1, c - 3) + 1, dp[a][b][c]);
	dp[a][b][c] = min(attack(a - 3, b - 9, c - 1) + 1, dp[a][b][c]);
	dp[a][b][c] = min(attack(a - 3, b - 1, c - 9) + 1, dp[a][b][c]);
	dp[a][b][c] = min(attack(a - 1, b - 3, c - 9) + 1, dp[a][b][c]);
	dp[a][b][c] = min(attack(a - 1, b - 9, c - 3) + 1, dp[a][b][c]);
	return dp[a][b][c];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> SCV[i];
	memset(visited, false, sizeof(visited));
	dp[0][0][0] = 0;
	cout << attack(SCV[0], SCV[1], SCV[2]);

	return 0;
}