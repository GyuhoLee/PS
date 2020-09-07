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

int T, N, K, cnt, qCnt, zCnt, oCnt, digit[300001];
string str, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		ans = "YES";
		CIN3(N, K, str);
		FUP(i, 0, K - 1) digit[i] = -1;
		FUP(i, 0, str.length() - 1)
		{
			if (digit[i % K] == -1)
			{
				if (str[i] != '?') digit[i % K] = str[i] - '0';
			}
			else
			{
				if (str[i] != '?' && digit[i % K] != str[i] - '0')
				{
					ans = "NO";
					break;
				}
			}
		}
		cnt = qCnt = zCnt = oCnt = 0;
		FUP(i, 0, K - 1)
		{
			if (str[i] == '?')
			{
				if (digit[i] == -1) qCnt++;
				else if (digit[i] == 0) zCnt++;
				else oCnt++;
			}
			else cnt += (str[i] - '0');
		}
		if (cnt + oCnt > K / 2 || cnt + oCnt + qCnt < K / 2) ans = "NO";
		COUT(ans);
		ENDL;
	}

	return 0;
}