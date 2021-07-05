#include <iostream>
#include <queue>
using namespace std;
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };

int N, M, visited[1002][1000];
string arr[1002];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) arr[0] += '0';
	arr[N + 1] = arr[0];
	for (int i = 1; i <= N; i++) cin >> arr[i];

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = 1;
	while (!q.empty())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny > N + 1 || nx < 0 || nx >= M || visited[ny][nx] || arr[ny][nx] == '1') continue;
			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
	visited[N + 1][0] ? cout << "YES" : cout << "NO";

	return 0;
}