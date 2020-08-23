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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int H, M, S, h, m, s, ans = 0;
	char ch;
	CIN3(H, ch, M);
	CIN2(ch, S);
	CIN3(h, ch, m);
	CIN2(ch, s);
	int X = H * 3600 + M * 60 + S;
	int x = h * 3600 + m * 60 + s;
	ans = x - X;
	if (ans < 0) ans += (3600 * 24);
	COUT(ans);


	return 0;
}