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

int arr[2187][2187];
int answer[3];
int N;

void solve(int y, int x, int size)
{
	int num = arr[y][x];
	if (size == 1)
	{
		answer[num]++;
		return;
	}
	bool same = true;
	FUP(i, y, y + size - 1)
	{
		FUP(j, x, x + size - 1)
		{
			if (arr[i][j] != num)
			{
				same = false;
				break;
			}
		}
		if (!same) break;
	}
	if (same) answer[num]++;
	else
	{
		int newSize = size / 3;
		solve(y, x, newSize);
		solve(y + newSize, x, newSize);
		solve(y + 2 * newSize, x, newSize);
		solve(y, x + newSize, newSize);
		solve(y + newSize, x + newSize, newSize);
		solve(y + 2 * newSize, x + newSize, newSize);
		solve(y, x + 2 * newSize, newSize);
		solve(y + newSize, x + 2 * newSize, newSize);
		solve(y + 2 * newSize, x + 2 * newSize, newSize);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(answer, 0);
	CIN(N);
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, N - 1)
		{
			CIN(arr[i][j]);
			arr[i][j]++;
		}
	}
	solve(0, 0, N);
	FUP(i, 0, 2)
	{
		COUT(answer[i]);
		ENDL;
	}

	return 0;
}