#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N;
int arr[1000];
int dp[1000];
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	FUP(i, 0, N - 1)
	{
		cin >> arr[i];
		dp[i] = arr[i];
		answer = max(dp[i], answer);
	}

	FUP(i, 1, N - 1)
	{
		FUP(j, 0, i - 1)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
				answer = max(dp[i], answer);
			}
		}
	}

	cout << answer;

	return 0;
}