#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
int arr[20][20];
bool visited[20][20];
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int fish = 2;
int eat = 0;
int answer = 0;
pair<int, int> now;

struct node
{
	int y, x, time;
	node(int a, int b, int c) :y(a), x(b), time(c) {};
};

bool cmp(const node& p1, const node& p2) {
	if (p1.y < p2.y) {
		return true;
	}
	else if (p1.y == p2.y) {
		return p1.x < p2.x;
	}
	else {
		return false;
	}
}

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] == 9)
			{
				arr[i][j] = 0;
				now = make_pair(i, j);
			}
		}
	}
}

bool BFS()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;
		}
	}
	visited[now.first][now.second] = true;
	queue<node> q;
	q.push(node(now.first, now.second, 0));
	vector<node> v;
	while (!q.empty())
	{
		node temp(q.front().y, q.front().x, q.front().time);
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = temp.y + dy[i];
			int nx = temp.x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < N && nx < N)
			{
				if ((!arr[ny][nx] || arr[ny][nx] == fish) && !visited[ny][nx])
				{
					visited[ny][nx] = true;
					q.push(node(ny, nx, temp.time + 1));
				}
				else if (arr[ny][nx] < fish && arr[ny][nx])
				{
					visited[ny][nx] = true;
					if (v.empty()) v.push_back(node(ny, nx, temp.time + 1));
					else
					{
						if (v[0].time == temp.time + 1) v.push_back(node(ny, nx, temp.time + 1));
						else
						{
							while (!q.empty()) { q.pop(); }
							break;
						}
					}

				}
			}
		}
	}
	if (v.empty()) return false;
	sort(v.begin(), v.end(), cmp);
	arr[v[0].y][v[0].x] = 0;
	now = make_pair(v[0].y, v[0].x);
	eat++;
	if (fish == eat)
	{
		fish++;
		eat = 0;
	}
	answer += v[0].time;
	return true;
	
}

int main()
{
	input();
	while (BFS()) {}
	printf("%d", answer);

	return 0;
}