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
#define INF 1111111

int T, N;
string str;
char ch;
int dp[200000][4], answer;

// RL, RRL, RLL, RRLL
void DP()
{
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, 3)
		{
			dp[i][j] = INF;
		}
	}
	FUP(i, 0, N - 1)
	{
		int num = INF;
		if (i == 0) num = 0;
		if (i >= 2) num = min(num, dp[i - 2][0]);
		if (i >= 3)
		{
			num = min(num, dp[i - 3][1]);
			num = min(num, dp[i - 3][2]);
		}
		if (i >= 4) num = min(num, dp[i - 4][3]);
		
		if (i + 1 < N)
		{
			dp[i][0] = num;
			if (str[i] != 'R') dp[i][0]++;
			if (str[i + 1] != 'L') dp[i][0]++;
		}
		if (i + 2 < N)
		{
			dp[i][1] = dp[i][2] = num;
			if (str[i] != 'R')
			{
				dp[i][1]++;
				dp[i][2]++;
			}
			if (str[i + 1] != 'R') dp[i][1]++;
			else dp[i][2]++;
			if (str[i + 2] != 'L')
			{
				dp[i][1]++;
				dp[i][2]++;
			}
		}
		if (i + 3 < N)
		{
			dp[i][3] = num;
			if (str[i] != 'R') dp[i][3]++;
			if (str[i + 1] != 'R') dp[i][3]++;
			if (str[i + 2] != 'L') dp[i][3]++;
			if (str[i + 3] != 'L') dp[i][3]++;

		}
	}
	answer = min(answer, dp[N - 2][0]);
	answer = min(answer, dp[N - 3][1]);
	answer = min(answer, dp[N - 3][2]);
	if(N > 3) answer = min(answer, dp[N - 4][3]);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		CIN2(N, str);
		answer = INF;
		DP();
		ch = str.front();
		str = str.substr(1) + str[0];
		DP();
		str = str.substr(1) + str[0];
		DP();
		str = str.substr(1) + str[0];
		DP();
		COUT(answer);
		ENDL;
	}

	return 0;
}