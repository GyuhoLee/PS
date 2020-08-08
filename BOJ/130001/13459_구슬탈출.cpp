#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
char arr[10][10];
bool visited[10][10][10][10];
pair<int, int> red;
pair<int, int> blue;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };	//하, 상, 좌, 우
int answer = -1;

struct node
{
	pair<int, int> ball[2]; //0이 빨간구슬, 1이 파란구슬
	int cnt;
	node(int a, int b, int c, int d, int e)
	{
		ball[0] = make_pair(a, b);
		ball[1] = make_pair(c, d);
		cnt = e;
	}
};

queue<node> q;

void input()
{
	memset(visited, false, sizeof(visited));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
			{
				arr[i][j] = '.';
				red = make_pair(i, j);
			}
			if (arr[i][j] == 'B')
			{
				arr[i][j] = '.';
				blue = make_pair(i, j);
			}
		}
	}
}

void move(node nod, int go)
{
	int fst;
	red = nod.ball[0];
	blue = nod.ball[1];
	pair<int, int> temp = make_pair(-1, -1);
	switch (go)	// 무슨 공을 먼저 움직일 것이냐.
	{
	case 0:
		if (red.first > blue.first) fst = 0;
		else fst = 1;
		break;
	case 1:
		if (red.first < blue.first) fst = 0;
		else fst = 1;
		break;
	case 2:
		if (red.second < blue.second) fst = 0;
		else fst = 1;
		break;
	case 3:
		if (red.second > blue.second) fst = 0;
		else fst = 1;
		break;
	}

	bool escape[2] = { false, false };

	for (int i = 0; i < 2; i++)
	{
		while (true)
		{
			int ny = nod.ball[fst].first+ dy[go];
			int nx = nod.ball[fst].second + dx[go];
			if (arr[ny][nx] == '#' || temp == make_pair(ny,nx))
			{
				break;
			}
			else if (arr[ny][nx] == 'O')
			{
				escape[fst] = true;
				break;
			}
			nod.ball[fst].first = ny;
			nod.ball[fst].second = nx;
		}
		temp = make_pair(nod.ball[fst].first, nod.ball[fst].second);
		if (escape[fst]) temp = make_pair(-1, -1);
		fst = (fst + 1) % 2;
	}
	red = nod.ball[0];
	blue = nod.ball[1];
	if (escape[1])
	{
		return;
	}
	if (escape[0])
	{
		answer = nod.cnt + 1;
		return;
	}
	if (!visited[red.first][red.second][blue.first][blue.second])
	{
		q.push(node(red.first, red.second, blue.first, blue.second, nod.cnt + 1));
	}
}

void BFS()
{
	q.push(node(red.first, red.second, blue.first, blue.second, 0));
	while (!q.empty())
	{
		if (answer != -1) break;
		node temp = q.front();
		if (temp.cnt == 10) break;
		visited[temp.ball[0].first][temp.ball[0].second][temp.ball[1].first][temp.ball[1].second] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			move(temp, i);
		}
	}
	if(answer == -1) cout << 0;
    else cout << 1;
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