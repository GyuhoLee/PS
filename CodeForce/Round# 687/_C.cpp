#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(ll i = a; i <= b; i++)
#define FDOWN(i, a, b) for(ll i = a; i >= b; i--)
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

ll T, N, P, K, X, Y, ans;
char arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		ans = LLONG_MAX;
		CIN3(N, P, K);
		FUP(i, 1, N) CIN(arr[i]);
		CIN2(X, Y);
		FUP(i, P, P + K - 1)
		{
			if (i > N) break;
			ll node = 0;
			ll cnt = Y * (i - P);
			
			for (ll j = i; j <= N; j += K)
			{
				node += K;
				if (arr[j] == '1') continue;
				else
				{
					if ((j + K <= N) && Y * (i - P) + node * Y <= cnt + X)
					{
						cnt = Y * (i - P) + node * Y;
					}
					else
					{
						cnt += X;
					}
				}
			}
			ans = min(ans, cnt);
		}
		COUT(ans);
		ENDL;
	}

	return 0;
}