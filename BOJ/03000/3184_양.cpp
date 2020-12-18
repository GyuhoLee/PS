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

char arr[251][251];
int R, C, V = 0, O = 0, v, o;
bool visited[251][251];

void DFS(int y, int x)
{
	visited[y][x] = true;
	if (arr[y][x] == 'o') o++;
	else if (arr[y][x] == 'v') v++;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > R || nx > C || visited[ny][nx] || arr[ny][nx] == '#') continue;
		DFS(ny, nx);
	}
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
			visited[i][j] = false;
		}
	}

	FUP(i, 1, R)
	{
		FUP(j, 1, C)
		{
			if (visited[i][j] || arr[i][j] == '#') continue;
			v = o = 0;
			DFS(i, j);
			if (o > v) O += o;
			else V += v;
		}
	}
	COUT2(O, V);


	return 0;
}