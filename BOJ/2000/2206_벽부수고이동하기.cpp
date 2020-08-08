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
bool visited[1000][1000][2];
int arr[1000][1000];
struct Node
{
	int y, x, cnt, wall;
	Node(int _y, int _x, int _cnt, int _wall) : y(_y), x(_x), cnt(_cnt), wall(_wall) {}
};

int BFS()
{
	MS(visited, false);
	queue<Node> q;
	q.push(Node(0, 0, 1, 0));
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();
		if (node.y == N - 1 && node.x == M - 1) return node.cnt;
		FUP(i, 0, 3)
		{
			int ny = node.y + dy[i];
			int nx = node.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[ny][nx] && !node.wall && !visited[ny][nx][1])
			{
				visited[ny][nx][1] = true;
				q.push(Node(ny, nx, node.cnt + 1, 1));
			}
			if (!arr[ny][nx] && !visited[ny][nx][node.wall])
			{
				visited[ny][nx][node.wall] = true;
				q.push(Node(ny, nx, node.cnt + 1, node.wall));
			}
		}

	}
	return -1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, M - 1)
		{
			scanf_s("%1d", &arr[i][j]);
		}
	}

	cout << BFS();
	
	return 0;
}