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

int N, M, arr[101][101], T, bf = 0;
stack<pair<int, int>> cheese;

void makeAir(int y, int x)
{
	arr[y][x] = -1;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
		if (arr[ny][nx] == 0)
		{
			arr[ny][nx] = -1;
			makeAir(ny, nx);
		}
		else if (arr[ny][nx] == 1)
		{
			arr[ny][nx] = 2;
			cheese.push({ ny, nx });
		}
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
		{
			CIN(arr[i][j]);
		}
	}
	FUP(i, 1, N)
	{
		if (arr[i][1] == 0)
		{
			makeAir(i, 1);
		}
		if (arr[i][M] == 0)
		{
			makeAir(i, M);
		}
	}
	FUP(j, 1, M)
	{
		if (arr[1][j] == 0)
		{
			makeAir(1, j);
		}
		if (arr[N][j] == 0)
		{
			makeAir(N, j);
		}
	}

	while (true)
	{
		if (cheese.size() == 0)
		{
			COUT(T);
			ENDL;
			COUT(bf);
			break;
		}
		bf = cheese.size();
		stack<pair<int, int>> newCheese;
		while (!cheese.empty())
		{
			newCheese.push(cheese.top());
			cheese.pop();
		}
		while (!newCheese.empty())
		{
			int y = newCheese.top().first;
			int x = newCheese.top().second;
			newCheese.pop();
			makeAir(y, x);
		}
		T++;
	}

	return 0;
}