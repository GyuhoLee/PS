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

int R, G, B, r[201], g[201], b[201];
ll dp[201][201][201];

ll DP(int rr, int gg, int bb)
{
	if (dp[rr][gg][bb] != -1) return dp[rr][gg][bb];
	dp[rr][gg][bb] = 0;
	if(rr && gg) dp[rr][gg][bb] = max(dp[rr][gg][bb], DP(rr - 1, gg - 1, bb) + (r[rr] * g[gg]));
	if(rr && bb) dp[rr][gg][bb] = max(dp[rr][gg][bb], DP(rr - 1, gg, bb - 1) + (r[rr] * b[bb]));
	if(gg && bb) dp[rr][gg][bb] = max(dp[rr][gg][bb], DP(rr, gg - 1, bb - 1) + (g[gg] * b[bb]));

	return dp[rr][gg][bb];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(R, G, B);
	FUP(i, 1, R) CIN(r[i]);
	FUP(i, 1, G) CIN(g[i]);
	FUP(i, 1, B) CIN(b[i]);
	r[0] = g[0] = b[0] = 0;
	sort(r, r + R + 1);
	sort(g, g + G + 1);
	sort(b, b + B + 1);
	MS(dp, -1);

	COUT(DP(R, G, B));


	return 0;
}