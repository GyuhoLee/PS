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

	int N, M;
	CIN2(N, M);
	int d[100][100];
	int answer[100];
	MS(answer, 0);
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, N - 1)
		{
			if (i == j) d[i][j] = 0;
			else d[i][j] = 101;
		}
	}
	while (M--)
	{
		int a, b;
		CIN2(a, b); a--; b--;
		d[a][b] = 1;
		d[b][a] = 1;
	}
	FUP(k, 0, N - 1)
	{
		FUP(i, 0, N - 1)
		{
			FUP(j, 0, N - 1)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int min_num = 10000000;
	int min_idx = 0;

	FUP(i, 0, N - 1)
	{
		FUP(j, 0, N - 1)
		{
			answer[i] += d[i][j];
		}
		if (answer[i] < min_num)
		{
			min_idx = i + 1;
			min_num = answer[i];
		}
	}
	COUT(min_idx);

	return 0;
}