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
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int R, C, K, num = 1, arr[1002][1002], d = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(C, R, K);
	if (K > C * R)
	{
		COUT("0");
		return 0;
	}
	FUP(i, 0, C + 1) arr[0][i] = arr[R + 1][i] = -1;
	FUP(i, 0, R + 1) arr[i][0] = arr[i][C + 1] = -1;
	int y = 1, x = 1;
	while (true)
	{
		if (num == K)
		{
			COUT2(x, y);
			break;
		}
		arr[y][x] = num++;
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (arr[ny][nx])
		{
			d = (d + 1) % 4;
			ny = y + dy[d];
			nx = x + dx[d];
		}
		y = ny;
		x = nx;
	}

	return 0;
}