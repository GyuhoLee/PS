#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[1001][1001];
bool visited[1001][1001];
bool can = true;
//»óÁÂÇÏ¿ì UDLR
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
char answer[1001][1001];
map<int, int> X;
queue<pair<int, int>> q;


void input()
{
	memset(visited, false, sizeof(visited));
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			answer[i][j] = 'z';
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j].first >> arr[i][j].second;
			if (arr[i][j].first != -1)
			{
				answer[arr[i][j].first][arr[i][j].second] = 'X';
				X.insert(arr[i][j]);
			}
		}
	}
}
void drawX()
{
	for (auto s : X)
	{
		if (arr[s.first][s.second].first != s.first || arr[s.first][s.second].second != s.second || s.first > N || s.second > N)
		{
			can = false;
			return;
		}
		visited[s.first][s.second] = true;
		q.push(s);
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny > N || nx > N || ny <= 0 || nx <= 0 || visited[ny][nx] || arr[ny][nx].first != s.first || arr[ny][nx].second != s.second) continue;
				q.push({ ny, nx });
				visited[ny][nx] = true;
				switch (i)
				{
				case 0: answer[ny][nx] = 'D'; break;
				case 1: answer[ny][nx] = 'R'; break;
				case 2: answer[ny][nx] = 'U'; break;
				case 3: answer[ny][nx] = 'L'; break;
				}
			}
		}
	}
}

void draw2()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j].first != -1)
			{
				if (answer[i][j] == 'z')
				{
					can = false;
					return;
				}
				continue;
			}
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny > N || nx > N || ny <= 0 || nx <= 0) continue;
				if (arr[ny][nx].first == -1)
				{
					switch (k)
					{
					case 0: answer[i][j] = 'U'; break;
					case 1: answer[i][j] = 'L'; break;
					case 2: answer[i][j] = 'D'; break;
					case 3: answer[i][j] = 'R'; break;
					}
					break;
				}
			}
			if (answer[i][j] == 'z')
			{
				can = false;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	drawX();
	draw2();
	
	if (can)
	{
		cout << "VALID\n";
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << answer[i][j];
			}
			cout << '\n';
		}
	}
	else cout << "INVALID";

	return 0;
}