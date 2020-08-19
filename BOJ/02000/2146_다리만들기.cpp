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

int N, arr[100][100], answer = 10001, color = 0;
bool visited[100][100];

void DFS(int y, int x)
{
	arr[y][x] = color;
	visited[y][x] = true;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || !arr[ny][nx] || visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}

int BFS(int col)
{
	MS(visited, false);
	queue<pair<int, pair<int, int>>> q;
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, N - 1)
		{
			if (arr[i][j] == col)
			{
				q.push({ 0, { i, j } });
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty())
	{
		int dis = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
			if (arr[ny][nx]) 
				return dis;
			visited[ny][nx] = true;
			q.push({ dis + 1, {ny, nx} });
		}
	}
	return 10001;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, N - 1)
		{
			CIN(arr[i][j]);
		}
	}
	MS(visited, false);

	FUP(i, 0, N - 1)
	{
		FUP(j, 0, N - 1)
		{
			if (!arr[i][j] || visited[i][j]) continue;
			color++;
			DFS(i, j);
		}
	}
	FUP(i, 1, color)
	{
		answer = min(answer, BFS(i));
	}
	COUT(answer);

	return 0;
}