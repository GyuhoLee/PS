#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, arr[1000], dp[1000], before[1000], len, idx;

void Print(int node)
{
	if (before[node] != node) Print(before[node]);
	COUT2(arr[node], "");
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1) CIN(arr[i]);
	dp[0] = 1; before[0] = 0; len = 1; idx = 0;
	FUP(i, 1, N - 1)
	{
		dp[i] = 1;
		before[i] = i;
		FUP(j, 0, i - 1)
		{
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				before[i] = j;
			}
		}
		if (len < dp[i])
		{
			len = dp[i];
			idx = i;
		}
	}
	COUT(len);
	ENDL;
	Print(idx);

	return 0;
}