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
#define INF 987654321

int V, E, d[401][401], ans = INF;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(&d[0][0], &d[400][401], INF);
	CIN2(V, E);
	while (E--)
	{
		int a, b, c;
		CIN3(a, b, c);
		d[a][b] = c;
	}
	FUP(k, 1, V)
	{
		FUP(j, 1, V)
		{
			FUP(i, 1, V)
			{
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	FUP(i, 1, V) ans = min(ans, d[i][i]);
	COUT((ans == INF ? -1 : ans));

	return 0;
}