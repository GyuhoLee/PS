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

ll T, P, F, s, w, cnts, cntw;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		ll ans = 0;
		CIN2(P, F);
		if (P > F) swap(P, F);
		CIN2(cnts, cntw);
		CIN2(s, w);
		if (s > w)
		{
			swap(s, w);
			swap(cnts, cntw);
		}
		ll First = cnts;
		ll can = P / s;
		if (cnts <= can)
		{
			ans += cnts;
			P -= (s * cnts);
			cnts = 0;
		}
		else
		{
			ans += can;
			cnts -= can;
			P -= (s * can);
		}
		can = P / w;
		if (cntw <= can)
		{
			ans += cntw;
			P -= (w * cntw);
			cntw = 0;
		}
		else
		{
			ans += can;
			cntw -= can;
			P -= (w * can);
		}
		if (P)
		{
			ll diff = w - s;
			if (diff != 0)
			{
				can = P / diff;
				ll tmp1 = cnts, tmp2 = cntw;
				cnts += can;
				cntw -= can;
				if (cntw < 0)
				{
					cnts += cntw;
					cntw = 0;
				}
				if (cnts > First)
				{
					cntw += (cnts - First);
					cnts = First;
				}
				if (cntw < 0)
				{
					cnts = tmp1;
					cntw = tmp2;
				}
			}
		}

		P = F;
		can = P / s;
		if (cnts <= can)
		{
			ans += cnts;
			P -= (s * cnts);
			cnts = 0;
		}
		else
		{
			ans += can;
			cnts -= can;
			P -= (s * can);
		}
		can = P / w;
		if (cntw <= can)
		{
			ans += cntw;
			P -= (w * cntw);
			cntw = 0;
		}
		else
		{
			ans += can;
			cntw -= can;
			P -= (w * can);
		}
		COUT(ans);
		ENDL;


	}

	return 0;
}