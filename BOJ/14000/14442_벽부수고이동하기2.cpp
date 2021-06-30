#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M, K, dist[1000][1000][11];
string arr[1000];

struct Node
{
	int d, y, x, k;
	Node(int dd, int yy, int xx, int kk) : d(dd), y(yy), x(xx), k(kk) {}
};

struct compare
{
	bool operator()(const Node A, const Node B)
	{
		return A.d > B.d;
	}
};

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k <= K; k++)
				dist[i][j][k] = 1e9;
		}
	}
	priority_queue<Node, vector<Node>, compare> pq;
	pq.push(Node(1, 0, 0, 0));
	dist[0][0][0] = 1;
	while (!pq.empty())
	{
		Node node = pq.top();
		pq.pop();
		int d = node.d, y = node.y, x = node.x, k = node.k;
		if (d > dist[y][x][k]) continue;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (arr[ny][nx] == '1')
			{
				if (k != K && dist[ny][nx][k + 1] > d + 1)
				{
					dist[ny][nx][k + 1] = d + 1;
					pq.push(Node(d + 1, ny, nx, k + 1));
				}
			}
			else
			{
				if (dist[ny][nx][k] > d + 1)
				{
					dist[ny][nx][k] = d + 1;
					pq.push(Node(d + 1, ny, nx, k));
				}
			}
		}
	}
	int ans = dist[N - 1][M - 1][0];
	for (int i = 1; i <= K; i++) ans = min(ans, dist[N - 1][M - 1][i]);
	if (ans == 1e9) cout << -1;
	else cout << ans;

	return 0;
}