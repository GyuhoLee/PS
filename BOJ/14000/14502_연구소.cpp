#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
int arr[8][8];	//0 : ∫Ûƒ≠ // 1 : ∫Æ // 2 : πŸ¿Ã∑ØΩ∫
bool visited[8][8];
vector<pair<int, int>> map;
vector<int> permut;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int answer = 0;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (!arr[i][j])
			{
				map.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < map.size() - 3; i++)
	{
		permut.push_back(0);
	}
	for (int i = 0; i < 3; i++)
	{
		permut.push_back(1);
	}
}
void BFS()
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	int cnt = permut.size() - 3;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 2)
			{
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}
	while (!q.empty())
	{
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = ty + dy[i];
			int nx = tx + dx[i];
			if (ny < N && nx < M && ny >= 0 && nx >= 0)
			{
				if (!visited[ny][nx] && !arr[ny][nx])
				{
					visited[ny][nx] = true;
					cnt--;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	answer = max(answer, cnt);
}

void solve()
{
	do
	{
		for (int i = 0; i < permut.size(); i++)
		{
			if (permut[i])
			{
				arr[map[i].first][map[i].second] = 1;
			}
			else
			{
				arr[map[i].first][map[i].second] = 0;
			}
		}
		BFS();
	} while (next_permutation(permut.begin(), permut.end()));
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();

	return 0;
}
