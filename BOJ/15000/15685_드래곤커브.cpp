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
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

int N, x, y, d, g, ny, nx, nd, answer = 0;
bool visited[101][101];
stack<int> S, S2;

void draw(int yy, int xx, int dd)
{
	ny = yy + dy[dd];
	nx = xx + dx[dd];
	visited[ny][nx] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(visited, false);
	CIN(N);
	while (N--)
	{
		CIN2(x, y);
		CIN2(d, g);
		draw(y, x, d);
		visited[y][x] = true;
		S.push(d);
		FUP(i, 1, g)
		{
			S2 = S;
			while (!S2.empty())
			{
				nd = (S2.top() + 1) % 4;
				S2.pop();
				draw(ny, nx, nd);
				S.push(nd);
			}
		}
		while (!S.empty()) S.pop();
	}
	FUP(i, 0, 99)
	{
		FUP(j, 0, 99)
		{
			if (visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) answer++;
		}
	}
	COUT(answer);

	return 0;
}