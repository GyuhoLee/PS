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

int N, pos[100001], in[100001], post[100001], pre[100001];

void solve(int is, int ie, int ps, int pe)
{
	if (is > ie || ps > pe) return;
	int root = post[pe];
	COUT2(root, "");
	int idx = pos[root];
	int left = idx - is;
	solve(is, idx - 1, ps, ps + left - 1);
	solve(idx + 1, ie, ps + left, pe - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N) CIN(in[i]);
	FUP(i, 1, N) CIN(post[i]);
	FUP(i, 1, N) pos[in[i]] = i;
	solve(1, N, 1, N);


	return 0;
}