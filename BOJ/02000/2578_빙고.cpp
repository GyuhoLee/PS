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


int arr[5][5], cnt = 0;
bool ok[5][5];

void bingo(int y, int x)
{
	FUP(i, 0, 4)
	{
		if (ok[i][x] == false) break;
		if (i == 4) cnt++;
	}
	FUP(i, 0, 4)
	{
		if (ok[y][i] == false) break;
		if (i == 4) cnt++;
	}
	if (y == x)
	{
		FUP(i, 0, 4)
		{
			if (ok[i][i] == false) break;
			if (i == 4) cnt++;
		}
	}
	if (y + x == 4)
	{
		FUP(i, 0, 4)
		{
			if (ok[i][4 - i] == false) break;
			if (i == 4) cnt++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N = 25;
	FUP(i, 0, 4)
	{
		FUP(j, 0, 4)
		{
			CIN(arr[i][j]);
			ok[i][j] = false;
		}
	}
	while (N--)
	{
		int num;
		CIN(num);
		FUP(i, 0, 4)
		{
			FUP(j, 0, 4)
			{
				if (arr[i][j] == num)
				{
					ok[i][j] = true;
					bingo(i, j);
				}
			}
		}
		if (cnt >= 3)
		{
			COUT(25 - N);
			break;
		}

	}

	return 0;
}