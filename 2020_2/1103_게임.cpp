#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int N, M;
char arr[50][50];
vector<pair<int, int>> v[50][50];
int dp[50][50];
bool visited[50][50];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int answer = 1;
bool infinity = false;

void input()
{
	memset(dp, 0, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int num = arr[i][j] - '0';
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k] * num;
				int nx = j + dx[k] * num;
				if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 'H') continue;
				v[i][j].push_back(make_pair(ny, nx));
			}
		}
	}
}

void solve(int y, int x, int cnt)
{
	if (infinity) return;
	visited[y][x] = true;
	dp[y][x] = cnt;
	if (v[y][x].size() == 0)
	{
		answer = max(answer, cnt);
		visited[y][x] = false;
		return;
	}
	for (auto point : v[y][x])
	{
		if (visited[point.first][point.second])
		{
			answer = -1;
			infinity = true;
			return;
		}
		if (dp[point.first][point.second] >= cnt + 1) continue;
		visited[point.first][point.second] = true;
		solve(point.first, point.second, cnt + 1);
	}
	visited[y][x] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve(0, 0, 1);
	cout << answer;

	return 0;
}