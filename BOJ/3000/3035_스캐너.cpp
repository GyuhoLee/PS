#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R, C, ZR, ZC;
	cin >> R >> C >> ZR >> ZC;
	char arr[50][50];
	FUP(i, 0, R - 1)
		FUP(j, 0, C - 1)
			cin >> arr[i][j];


	FUP(r, 0, R - 1)
	{
		FUP(zr, 1, ZR)
		{
			FUP(c, 0, C - 1)
			{
				FUP(zc, 1, ZC)
				{
					cout << arr[r][c];
				}
			}
			cout << ENDL;
		}
	}

	return 0;
}