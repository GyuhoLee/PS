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

int N, M, dp[1001][1001], answer = 0;
char arr[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
		{
			CIN(arr[i][j]);
		}
	}
	FUP(i, 1, N) dp[i][1] = arr[i][1] - '0';
	FUP(j, 2, M) dp[1][j] = arr[1][j] - '0';
	FUP(i, 2, N)
	{
		FUP(j, 2, M)
		{
			if (arr[i][j] == '1') dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
			else dp[i][j] = 0;
		}
	}
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
		{
			answer = max(answer, dp[i][j]);
		}
	}
	COUT(answer * answer);

	return 0;
}