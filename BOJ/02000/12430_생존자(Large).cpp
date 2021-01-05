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

int T, N;
pair<int, int> food[1001];
bool dp[1001][101001];

bool comp(pair<int, int> x, pair<int, int> y)
{
	return x.first + x.second < y.first + y.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	food[0] = { 0, 0 };
	CIN(T);
	FUP(t, 1, T)
	{
		MS(dp, false);
		dp[0][0] = true;
		int maxTime = 0;
		CIN(N);
		FUP(i, 1, N) CIN2(food[i].first, food[i].second);
		sort(food, food + N + 1, comp);
		FUP(i, 1, N)
		{
			FUP(j, 0, maxTime)
			{
				if (dp[i - 1][j])
				{
					dp[i][j] = true;
					if (j <= food[i].first)
					{
						dp[i][j + food[i].second] = true;
						maxTime = max(maxTime, j + food[i].second);
					}
				}
			}
		}
		COUT("Case #" + to_string(t) + ": " + to_string(maxTime) + "\n");
	}

	return 0;
}