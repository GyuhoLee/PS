#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int K, W, H;
vector<int> arr[200];
struct point {
	int x;
	int y;
	int k;
	int cnt;
	point() {};
	point(int d_x, int d_y, int d_k, int d_cnt) : x(d_x), y(d_y), k(d_k), cnt(d_cnt) {};
};

bool visit[200][200][30] = { false, };
vector<int> sx = { 1, -1, 0, 0, 2, 2, 1, 1, -1, -1, -2, -2};
vector<int> sy = { 0, 0, 1, -1, 1, -1, 2, -2, 2, -2, 1, -1 };

void input();
void BFS();

int main()
{
	input();
	BFS();

	return 0;
}

void input()
{
	scanf_s("%d", &K);
	scanf_s("%d %d", &W, &H);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			int temp;
			scanf_s("%d", &temp);
			arr[i].push_back(temp);
		}
	}
}

//(H,W)

void BFS()
{
	queue<point> q;
	q.push(point(0, 0, K, 0));
	while (!q.empty())
	{
		point now;
		now = q.front();
		q.pop();
		if (now.x == W - 1 && now.y == H - 1)
		{
			printf("%d", now.cnt);
			return;
		}
		if (visit[now.y][now.x][now.k]) continue;
		visit[now.y][now.x][now.k] = true;
		int kplus = 0;
		for (int i = 0; i < 12; i++)
		{
			if (i == 4)
			{
				if (now.k == 0) break;
				kplus = 1;
			}
			point tp(now.x + sx[i], now.y + sy[i], now.k - kplus, now.cnt + 1);
			if (tp.x < 0 || tp.y < 0 || tp.x >= W || tp.y >= H || arr[tp.y][tp.x] == 1) continue;
			q.push(tp);
		}
	}
	printf("-1");
}