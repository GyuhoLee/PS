#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> snake;
bool visited[101][101];
bool apple[101][101];
queue<pair<int, char>> turn;
int N, K, L;
int go = 0;
int time = 0;
int y = 1, x = 1;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void input()
{
	cin >> N >> K;
	memset(apple, false, sizeof(apple));
	memset(visited, false, sizeof(visited));
	while (K--)
	{
		int a, b;
		cin >> a >> b;
		apple[a][b] = true;
	}
	cin >> L;
	while (L--)
	{
		int a; char b;
		cin >> a >> b;
		turn.push(make_pair(a , b));
	}
	snake.push(make_pair(y, x));
	visited[y][x] = true;
}

bool move()
{
	time++;
	int ny = y + dy[go];
	int nx = x + dx[go];
	if (ny <= 0 || nx <= 0 || ny > N || nx > N || visited[ny][nx]) return false;
	if (apple[ny][nx])
	{
		apple[ny][nx] = false;
	}
	else
	{
		visited[snake.front().first][snake.front().second] = false;
		snake.pop();
	}
	snake.push(make_pair(ny, nx));
	visited[ny][nx] = true;
	y = ny;
	x = nx;
	if (!turn.empty() && turn.front().first == time)
	{
		if (turn.front().second == 'D') go = (go + 1) % 4;
		else go = (go + 3) % 4;
		turn.pop();
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	while (move()) {}
	cout << time;
	
	return 0;
}