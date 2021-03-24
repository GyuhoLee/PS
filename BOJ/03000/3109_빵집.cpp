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

int R, C, ans = 0;
char arr[10001][501];

bool DFS(int i, int j)
{
	if (i < 1 || i > R || arr[i][j] == 'x') return false;
	arr[i][j] = 'x';
	if (j == C)
	{
		return true;
	}
	if (DFS(i - 1, j + 1)) return true;
	else if (DFS(i, j + 1)) return true;
	else if (DFS(i + 1, j + 1)) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(R, C);
	FUP(i, 1, R)
	{
		FUP(j, 1, C)
		{
			CIN(arr[i][j]);
		}
	}
	FUP(i, 1, R)
	{
		ans += DFS(i, 1);
	}
	COUT(ans);

	return 0;
}