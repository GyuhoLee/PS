#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <limits.h>
#include <queue>
using namespace std;

int N, M;
int arr[50][50];
bool visited[50][50];
vector<pair<int, int>> virus;
int emptyCnt = 0;
vector<int> permut;
queue<pair<pair<int, int>, int>> q;
int answer = INT_MAX;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				virus.push_back(make_pair(i, j));
				permut.push_back(0);
			}
			else if (!arr[i][j]) emptyCnt++;
		}
	}
	for (int i = permut.size() - M; i < permut.size(); i++)
		permut[i] = 1;
}

void BFS()
{
	do
	{
		memset(visited, false, sizeof(visited));
		int emt = emptyCnt;
		int time = 0;
		for (int i = 0; i < permut.size(); i++)
		{
			if (permut[i])
			{
				q.push(make_pair(virus[i], 0));
				visited[virus[i].first][virus[i].second] = true;
			}
		}
		while (!q.empty())
		{
			pair<int, int> node = q.front().first;
			int cnt = q.front().second;
			if (!arr[node.first][node.second]) time = max(cnt, time);
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = node.first + dy[i];
				int nx = node.second + dx[i];
				if (ny >= 0 && nx >= 0 && ny < N && nx < N && arr[ny][nx] != 1 && !visited[ny][nx])
				{
					visited[ny][nx] = true;
					q.push(make_pair(make_pair(ny, nx), cnt + 1));
					if (!arr[ny][nx]) emt--;
				}
			}
		}
		if (emt) continue;
		answer = min(answer, time);
	} while (next_permutation(permut.begin(), permut.end()));
	if (answer == INT_MAX) answer = -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	BFS();
	cout << answer;

	return 0;
}