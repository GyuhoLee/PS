#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int Dp[100001];
	MS(Dp, 0);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			if (Dp[i] > Dp[i - j * j] + 1 || Dp[i] == 0) Dp[i] = Dp[i - j * j] + 1;
		}
	}

	cout << Dp[N];


	return 0;
}