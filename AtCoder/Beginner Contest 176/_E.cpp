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

int H, W, M, h[300001], w[300001], mh = 0, mw = 0;
set<pair<int, int>> S;
vector<int> vh, vw;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(h, 0);
	MS(w, 0);
	CIN3(H, W, M);
	while (M--)
	{
		int hh, ww;
		CIN2(hh, ww);
		S.insert({ hh, ww });
		if (mh < ++h[hh])
		{
			vh.clear();
			mh = h[hh];
			vh.push_back(hh);
		}
		else if (mh == h[hh]) vh.push_back(hh);
		if (mw < ++w[ww])
		{
			vw.clear();
			mw = w[ww];
			vw.push_back(ww);
		}
		else if (mw == w[ww]) vw.push_back(ww);
	}
	for (int hh : vh)
	{
		for (int ww : vw)
		{
			if (S.count({ hh, ww }) == 0)
			{
				COUT(mh + mw);
				return 0;
			}
		}
	}
	COUT(mh + mw - 1);

	return 0;
}