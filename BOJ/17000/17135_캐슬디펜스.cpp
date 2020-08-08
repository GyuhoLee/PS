#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, M, D;
int arr[16][16];
int enemy[16][16];
int answer = 0;

struct node {
	int a = 1;
	int b = 2;
	int c = 2;

	bool next()
	{
		if (c != M)
		{
			c++;
			return true;
		}
		if (b != M - 1)
		{
			b++;
			c = b + 1;
			return true;
		}
		if (a != M - 2)
		{
			a++;
			b = a + 1;
			c = a + 2;
			return true;
		}
		return false;
	}
};



struct point {
	int x;
	int y;
	point(int dy, int dx) :y(dy), x(dx) {}
};

queue<point> q;
node archur;

void input();
void solve();
void check(int dy, int dx);

int main()
{
	input();
	solve();
	printf("%d", answer);

	return 0;
}

void input()
{
	scanf_s("%d %d %d", &N, &M, &D);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
}

void solve()
{
	while (archur.next())
	{
		int height = N + 1;
		int kill = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				enemy[i][j] = arr[i][j];
			}
		}
		while (height > 1)
		{
			check(height, archur.a);
			check(height, archur.b);
			check(height, archur.c);
			height--;
			while (!q.empty())
			{
				point temp = q.front();
				q.pop();
				if (enemy[temp.y][temp.x])
				{
					enemy[temp.y][temp.x] = 0;
					kill++;
				}
			}
		}
		answer = max(kill, answer);
	}
}

void check(int dy, int dx)
{
	for (int i = 1; i <= D; i++)
	{
		bool isFind = false;
		for (int j = -1 * i + 1; j < i; j++)
		{
			int sx = dx + j;
			int sy = dy - (i - abs(j));
			if (sx < 1 || sx > M || sy < 1) continue;
			if (enemy[sy][sx])
			{
				isFind = true;
				q.push(point(sy, sx));
				break;
			}
		}
		if (isFind) break;
	}
}