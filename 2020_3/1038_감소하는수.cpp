#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[1000001];
queue<ll> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 10; i++)
	{
		dp[i] = i;
		q.push(i);
	}
	int idx = 10;
	while (!q.empty())
	{
		ll num = q.front();
		q.pop();
		for (int i = 0; i < num % 10; i++)
		{
			q.push(num * 10 + i);
			dp[idx] = num * 10 + i;
			idx++;
		}
	}
	int N;
	cin >> N;
	cout << dp[N];

	return 0;
}