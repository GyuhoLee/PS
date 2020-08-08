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
char arr[200][200];
bool visited[200][200];

struct Node
{
	int y, x;
	deque<pair<int, int>> road;

	Node(int yy, int xx) : y(yy), x(xx) {}
};

queue<Node> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deque<int> aa;
	MS(visited, false);
	cin >> N >> M;
	FUP(i, 1, N)
		FUP(j, 1, M)
			cin >> arr[i][j];


	Node temp(1, 1);
	temp.road.push_back({ 1, 1 });
	visited[1][1] = true;
	q.push(temp);
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();
		if (node.y == N && node.x == M)
		{
			while (!node.road.empty())
			{
				cout << node.road.front().first << ' ' << node.road.front().second << '\n';
				node.road.pop_front();
			}
			return 0;
		}
		FUP(i, 0, 3)
		{
			int ny = node.y + dy[i];
			int nx = node.x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > M || visited[ny][nx] || arr[ny][nx] == '*') continue;
			visited[ny][nx] = true;
			Node tmp(ny, nx);
			tmp.road = node.road;
			tmp.road.push_back({ ny, nx });
			q.push(tmp);

		}
	}

	return 0;
}