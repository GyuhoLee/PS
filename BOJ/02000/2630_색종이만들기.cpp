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

int N, arr[129][129], white = 0, blue = 0;

void solve(int y, int x, int n)
{
	int num = arr[y][x];
	bool ok = true;
	FUP(i, y, y + n - 1)
	{
		FUP(j, x, x + n - 1)
		{
			if (num != arr[i][j])
			{
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}
	if (ok)
	{
		num == 1 ? blue++ : white++;
	}
	else
	{
		solve(y, x, n / 2);
		solve(y + n / 2, x, n / 2);
		solve(y, x + n / 2, n / 2);
		solve(y + n / 2, x + n / 2, n / 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			CIN(arr[i][j]);
		}
	}
	solve(1, 1, N);
	COUT(white);
	ENDL;
	COUT(blue);

	return 0;
}