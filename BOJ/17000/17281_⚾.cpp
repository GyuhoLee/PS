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

int N, scoring[51][9], ans = 0, base[3];
vector<int> permut = { 1, 2, 3, 4, 5, 6, 7, 8 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N)
	{
		FUP(j, 0, 8)
		{
			CIN(scoring[i][j]);
		}
	}
	do
	{
		int score = 0;
		int idx = -1;
		FUP(i, 1, N)
		{
			int out = 0, batter, bat;
			base[0] = base[1] = base[2] = 0;
			while (out < 3)
			{
				idx = (idx + 1) % 9;
				if (idx < 3) batter = permut[idx];
				else if (idx == 3) batter = 0;
				else batter = permut[idx - 1];
				bat = scoring[i][batter];
				if (bat == 0)
				{
					out++;
					continue;
				}
				FDOWN(i, 2, 0)
				{
					if (!base[i]) continue;
					if (i + bat > 2) score++;
					else(base[i + bat] = 1);
					base[i] = 0;
				}
				if (bat == 4) score++;
				else base[bat - 1] = 1;
			}
		}
		ans = max(ans, score);
	} while (next_permutation(ALL(permut)));
	COUT(ans);

	return 0;
}