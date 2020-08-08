#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

struct Point
{
	int x, y;
	Point(int xx, int yy) :y(yy), x(xx) {}
	bool operator<(Point p)
	{
		if (x == p.x) return y < p.y;
		else return x < p.x;
	}
	bool operator>(Point p)
	{
		if (x == p.x) return y > p.y;
		else return x > p.x;
	}
	bool operator<=(Point p)
	{
		if (x == p.x) return y <= p.y;
		else return x <= p.x;
	}
	bool operator>=(Point p)
	{
		if (x == p.x) return y >= p.y;
		else return x >= p.x;
	}
};
int N;
vector<pair<Point, Point>> v;
vector<int> connect[3000];
bool visited[3000];
vector<int> line[3000];
int cnt = 0;

int ccw(Point a, Point b, Point c)
{
	int op = a.x * b.y + b.x * c.y + c.x * a.y;
	op -= (a.y * b.x + b.y * c.x + c.y * a.x);
	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

bool check(pair<Point, Point> a, pair<Point,Point> b)
{
	int ab = ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
	int cd = ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);
	if (ab == 0 && cd == 0)
	{
		if (a.first > a.second) swap(a.first, a.second);
		if (b.first > b.second) swap(b.first, b.second);
		return b.first <= a.second && a.first <= b.second;
	}
	return ab <= 0 && cd <= 0;
}

void input()
{
	memset(visited, false, sizeof(visited));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back(make_pair(Point(x1, y1), Point(x2, y2)));
		for (int j = 0; j < i; j++)
		{
			if (check(v[i], v[j]))
			{
				connect[i].push_back(j);
				connect[j].push_back(i);
			}
		}
	}
}

void DFS(int num)
{
	line[cnt].push_back(num);
	visited[num] = true;
	for (auto s : connect[num])
	{
		if (!visited[s]) DFS(s);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			DFS(i);
			cnt++;
		}
	}
	int Max = 1;
	for (int i = 0; i < cnt; i++)
	{
		int len = line[i].size();
		Max = max(Max, len);
	}
	cout << cnt << '\n' << Max;


	return 0;
}