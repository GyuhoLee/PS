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

int N, dp[2500];
string str;
bool pal[2500][2500];

bool isPal(int l, int r)
{
	while (l < r)
	{
		if (str[l] != str[r]) return false;
		l++;
		r--;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(str);
	N = str.length();
	FUP(i, 0, N - 1)
	{
		FUP(j, i, N - 1)
		{
			pal[i][j] = isPal(i, j);
		}
	}
	dp[0] = 1;
	FUP(i, 1, N - 1)
	{
		pal[0][i] ? dp[i] = 1 : dp[i] = INT_MAX;
		FUP(j, 0, i - 1)
		{
			if (!pal[j + 1][i]) continue;
			dp[i] = min(dp[i], 1 + dp[j]);
		}
	}
	COUT(dp[N - 1]);
	
	return 0;
}