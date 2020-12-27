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

int N, M, arr[101][101], ans = 0;
vector<pair<int, int>> v;

void check()
{
	v.clear();
	FUP(i, 2, N - 1)
	{
		FUP(j, 2, M - 1)
		{
			if (arr[i][j] == 1)
			{
				int cnt = 0;
				FUP(k, 0, 3)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (arr[ny][nx] == -1) cnt++;
				}
				if (cnt >= 2) v.push_back({ i, j });
			}
		}
	}
}

void makeAir(int y, int x)
{
	arr[y][x] = -1;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
		if (arr[ny][nx] == 0) makeAir(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
			CIN(arr[i][j]);
	}
	makeAir(1, 1);
	while (true)
	{
		check();
		if (v.empty()) break;
		ans++;
		for (auto p : v)
		{
			arr[p.first][p.second] = 0;
			makeAir(p.first, p.second);
		}
	}
	COUT(ans);

	return 0;
}