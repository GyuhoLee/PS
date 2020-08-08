#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
char arr[20][20];
bool visited[26];
int answer = 1;

void DFS(int y, int x, int cnt)
{
	answer = max(cnt, answer);
	visited[arr[y][x] - 'A'] = true;
	
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[arr[ny][nx] - 'A']) continue;
		DFS(ny, nx, cnt + 1);
	}

	visited[arr[y][x] - 'A'] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	FUP(i, 0, N - 1)
		FUP(j, 0, M - 1)
			cin >> arr[i][j];
	MS(visited, false);

	DFS(0, 0, 1);
	cout << answer;
	

	return 0;
}