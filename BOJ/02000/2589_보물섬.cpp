#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[50][50];
bool visited[50][50];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int answer = 0;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
}

void solve(int y, int x)
{
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int>> q;
	q.push({ { y, x }, 0 });
	visited[y][x] = true;
	while (!q.empty())
	{
		pair<int, int> node = q.front().first;
		int cnt = q.front().second;
		answer = max(answer, cnt);
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = node.first + dy[i];
			int nx = node.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] || arr[ny][nx] == 'W') continue;
			q.push({ { ny, nx }, cnt + 1 });
			visited[ny][nx] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	input();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if(arr[i][j] == 'L') solve(i, j);
	cout << answer;

	return 0;
}