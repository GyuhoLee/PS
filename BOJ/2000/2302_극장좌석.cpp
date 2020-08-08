#include <bits/stdc++.h>
using namespace std;

int N, M;
int dp[41];
int answer = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 40; i++) dp[i] = dp[i - 1] + dp[i - 2];
	cin >> N >> M;
	int before = 0;
	int temp = 0;
	while (M--)
	{
		cin >> temp;
		if(temp != 1 && temp - before != 1) answer *= dp[temp - before - 1];
		before = temp;
	}
	if(temp != N) answer *= dp[N - temp];
	cout << answer;
	

	return 0;
}