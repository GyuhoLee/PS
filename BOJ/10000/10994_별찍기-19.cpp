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

char arr[401][401];

void draw(int y, int x, int d)
{
	if (d == 1)
	{
		arr[y][x] = '*';
		return;
	}
	FUP(i, 0, 4 * (d - 1))
	{
		if (i == 0 || i == 4 * (d - 1))
		{
			FUP(j, 0, 4 * (d - 1))
			{
				arr[y + i][x + j] = '*';
			}
			continue;
		}
		arr[y + i][x] = '*';
		arr[y + i][x + 4 * (d - 1)] = '*';
	}
	draw(y + 2, x + 2, d - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	CIN(N);
	draw(0, 0, N);
	FUP(i, 0, 4 * (N - 1))
	{
		FUP(j, 0, 4 * (N - 1))
		{
			arr[i][j] == '*' ? COUT('*') : COUT(' ');
		}
		ENDL;
	}

	return 0;
}