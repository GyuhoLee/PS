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

int N;
double arr[10001], dp[10001], ans = 0;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	CIN(N);
	dp[0] = 1;
	FUP(i, 1, N)
	{
		CIN(arr[i]);
		if (dp[i - 1] > 1) dp[i] = dp[i - 1] * arr[i];
		else dp[i] = arr[i];
		ans = max(ans, dp[i]);
	}
	printf("%.3lf", ans);

	return 0;
}