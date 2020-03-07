#include <bits/stdc++.h>
using namespace std;

int N, T;
int arr[30];
bool dp[15001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(dp, false, sizeof(dp));
	dp[0] = true;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		queue<int> q;
		for (int j = 0; j <= 15000; j++)
		{
			if (dp[j])
			{
				q.push(j + temp);
				q.push(abs(j - temp));
			}
		}
		while (!q.empty())
		{
			dp[q.front()] = true;
			q.pop();
		}
	}
	cin >> T;
	while (T--)
	{
		int temp;
		cin >> temp;
		dp[temp] ? cout << "Y " : cout << "N ";
	}

	return 0;
}