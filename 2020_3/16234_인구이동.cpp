#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int arr[50][50];
bool line[50][50][4];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int answer = 0;
bool change = false;
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int cnt = 0;
int total = 0;
bool visited[50][50];

void input()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

}

void removeLine()
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (abs(arr[j][i] - arr[j][i + 1]) >= L && abs(arr[j][i] - arr[j][i + 1]) <= R)
			{
				change = true;
				line[j][i][3] = line[j][i + 1][2] = true;
			}
			if (abs(arr[i][j] - arr[i + 1][j]) >= L && abs(arr[i][j] - arr[i + 1][j]) <= R)
			{
				change = true;
				line[i][j][1] = line[i + 1][j][0] = true;
			}
		}
	}
}

void move()
{
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || !line[y][x][i] || visited[ny][nx]) continue;
			cnt++;
			total += arr[ny][nx];
			visited[ny][nx] = true;
			q.push({ ny, nx });
			v.push_back({ ny, nx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	while (1)
	{
		memset(line, false, sizeof(line));
		memset(visited, false, sizeof(visited));
		change = false;
		removeLine();
		if (!change) break;
		answer++;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					visited[i][j] = true;
					q.push({ i,j });
					v.push_back({ i, j });
					cnt = 1;
					total = arr[i][j];
					move();
					while (!v.empty())
					{
						int y = v.back().first;
						int x = v.back().second;
						v.pop_back();
						arr[y][x] = total / cnt;
					}
				}
			}
		}
	}
	cout << answer;
	return 0;
}