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
const int MAX = (1 << 8) + 1;

int K, arr[MAX][MAX];
char fold[30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x = 1, y = 1;
	CIN(K);
	FDOWN(i, 2 * K - 1, 0) CIN(fold[i]);
	CIN(arr[1][1]);
	FUP(f, 0, 2 * K - 1)
	{
		char ch = fold[f];
		if (ch == 'D')
		{
			FUP(i, 1, y)
			{
				FUP(j, 1, x)
				{
					arr[i + y][j] = arr[i][j];
				}
			}
			FUP(i, 1, y)
			{
				FUP(j, 1, x)
				{
					arr[i][j] = (arr[2 * y - i + 1][j] + 2) % 4;
				}
			}
			y *= 2;
		}
		else if (ch == 'U')
		{
			FUP(i, 1, y)
			{
				FUP(j, 1, x)
				{
					arr[2 * y - i + 1][j] = (arr[i][j] + 2) % 4;
				}
			}
			y *= 2;
		}
		else if (ch == 'R')
		{
			FUP(i, 1, y)
			{
				FUP(j, 1, x)
				{
					arr[i][j + x] = arr[i][j];
				}
			}
			FUP(i, 1, y)
			{
				FUP(j, 1, x)
				{
					arr[i][j] = arr[i][2 * x - j + 1] ^ 1;
				}
			}
			x *= 2;
		}
		else if (ch == 'L')
		{
			FUP(i, 1, y)
			{
				FUP(j, 1, x)
				{
					arr[i][2 * x - j + 1] = arr[i][j] ^ 1;
				}
			}
			x *= 2;
		}
	}

	FUP(i, 1, y)
	{
		FUP(j, 1, x)
		{
			COUT2(arr[i][j], "");
		}
		ENDL;
	}

	return 0;
}