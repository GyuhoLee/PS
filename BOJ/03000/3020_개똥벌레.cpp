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

int N, H, up[100000], down[100000], ans = 2000000, cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, H);
	N /= 2;
	FUP(i, 0, N - 1)
	{
		CIN2(down[i], up[i]);
	}
	sort(up, up + N);
	sort(down, down + N);
	FUP(i, 1, H)
	{
		int num = ((down + N) - lower_bound(down, down + N, i)) + ((up + N) - upper_bound(up, up + N, H - i));
		if (num < ans)
		{
			ans = num;
			cnt = 1;
		}
		else if (num == ans) cnt++;
	}
	COUT2(ans, cnt);

	return 0;
}