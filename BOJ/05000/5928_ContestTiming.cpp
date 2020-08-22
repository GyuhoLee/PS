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

	int D, H, M, ans = 0;
	CIN3(D, H, M);
	if (D == 11 && H < 11)
	{
		if (H < 11) COUT(-1);
		if (H == 11 && M < 11) COUT(-1);
	}
	else
	{
		if (M < 11)
		{
			M += 60;
			H--;
		}
		ans += (M - 11);
		if (H < 11)
		{
			H += 24;
			D--;
		}
		ans += (60 * (H - 11));
		ans += (1440 * (D - 11));
		COUT(ans);
	}

	return 0;
}