#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> x >> y;
	int answer;
	if (x > 0)
	{
		if (y > 0) answer = 1;
		else answer = 4;
	}
	else
	{
		if (y > 0) answer = 2;
		else answer = 3;
	}
	cout << answer;

	return 0;
}