#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		ll answer = 1;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			answer *= (M - i);
			answer /= (i + 1);
		}
		cout << answer << '\n';
	}

	return 0;
}