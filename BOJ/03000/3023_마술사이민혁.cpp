#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int R, C, A, B;
char arr[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	FUP(i, 1, R)
	{
		FUP(j, 1, C)
		{
			cin >> arr[i][j];
		}
	}
	FUP(i, R + 1, 2 * R)
	{
		FUP(j, 1, C)
		{
			arr[i][j] = arr[2 * R - i + 1][j];
		}
	}
	FUP(i, 1, 2 * R)
	{
		FUP(j, C + 1, 2 * C)
		{
			arr[i][j] = arr[i][2 * C - j + 1];
		}
	}
	cin >> A >> B;
	if (arr[A][B] == '.') arr[A][B] = '#';
	else arr[A][B] = '.';
	FUP(i, 1, 2 * R)
	{
		FUP(j, 1, 2 * C)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
	

	return 0;
}