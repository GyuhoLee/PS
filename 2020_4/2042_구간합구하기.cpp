#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

ll N, M, K, H = 1;
ll a, b, c;
ll Tree[2097153];

void change(ll idx, ll num)
{
	if (idx == 0) return;
	Tree[idx] += num;
	change(idx / 2, num);
}

ll solve(int s, int e)
{
	ll ret = 0;
	while (s <= e)
	{
		if (s % 2) ret += Tree[s];
		if (!(e % 2)) ret += Tree[e];
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(Tree, 0);
	cin >> N >> M >> K;
	M += K;

	while (H < N) { H *= 2; }
	FUP(i, 0, N - 1) cin >> Tree[H + i];
	FDOWN(i, H - 1, 1) Tree[i] = Tree[i * 2] + Tree[i * 2 + 1];

	while (M--)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			ll idx = H + b - 1;
			ll num = c - Tree[idx];
			Tree[idx] = c;
			change(idx / 2, num);
		}
		else
		{
			cout << solve(H + b - 1, H + c - 1) << '\n';
		}
	}


	return 0;
}