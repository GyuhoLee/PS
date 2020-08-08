#include <bits/stdc++.h>
using namespace std;

int N, M, A, B, K;
int arr[501][501];
bool visited[502][502];
int y, x, sy, sx;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int answer = -1;
queue<pair<pair<int, int>, int>> q;

void input()
{
	cin >> N >> M >> A >> B >> K;
	memset(arr, 0, sizeof(arr));
	memset(visited, false, sizeof(visited));
	while (K--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	cin >> y >> x >> sy >> sx;
}

bool check(int yy, int xx)
{
	visited[yy][xx] = true;
	if (yy <= 0 || xx <= 0 || yy + A > N + 1 || xx + B > M + 1) return false;
	for (int i = 0; i < B; i++)
	{
		if (arr[yy][xx + i]) return false;
		if (arr[yy + A - 1][xx + i]) return false;
	}
	for (int i = 0; i < A; i++)
	{
		if (arr[yy + i][xx]) return false;
		if (arr[yy + i][xx + B - 1]) return false;
	}
	return true;
}

void BFS()
{
	q.push({ {y, x}, 0 });
	visited[y][x] = true;
	while (!q.empty())
	{
		pair<int, int> node = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (node.first == sy && node.second == sx)
		{
			answer = cnt;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = node.first + dy[i];
			int nx = node.second + dx[i];
			if (!visited[ny][nx] && check(ny, nx)) q.push({ { ny, nx },cnt + 1 });
		}
	}
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	BFS();

	return 0;
}