#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N;
string str[64];

void solve(int y, int x, int num)
{
	if (num == 1)
	{
		cout << str[y][x];
		return;
	}
	bool same = true;
	char ch = str[y][x];
	FUP(i, y, y + num - 1)
	{
		FUP(j, x, x + num - 1)
		{
			if (ch != str[i][j])
			{
				same = false;
				break;
			}
		}
		if (!same) break;
	}
	if (same) cout << ch;
	else
	{
		cout << "(";
		solve(y, x, num / 2);
		solve(y, x + num / 2, num / 2);
		solve(y + num / 2, x, num / 2);
		solve(y + num / 2, x + num / 2, num / 2);
		cout << ")";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	FUP(i, 0, N - 1) cin >> str[i];
	solve(0, 0, N);

	return 0;
}