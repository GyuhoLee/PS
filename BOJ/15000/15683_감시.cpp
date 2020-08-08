#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int N, M, cnt = 0;
int arr[8][8];
pair<int, int> cctv[8];
int answer = 0;

void DFS(int idx, int sum)
{
	if (idx == cnt)
	{
		answer = min(sum, answer);
		return;
	}
	int y = cctv[idx].first;
	int x = cctv[idx].second;
	int num = arr[y][x];
	
	if (num == 1)
	{
		FUP(i, 0, 3)
		{
			queue<pair<int, int>> q;
			int ty = y;
			int tx = x;
			while (1)
			{
				ty += dy[i];
				tx += dx[i];
				if (ty >= N || tx >= M || ty < 0 || tx < 0) break;
				if (arr[ty][tx] == 6) break;
				if (arr[ty][tx] != 0) continue;
				arr[ty][tx] = 7;
				q.push({ ty, tx });
			}
			DFS(idx + 1, sum - q.size());
			while (!q.empty())
			{
				arr[q.front().first][q.front().second] = 0;
				q.pop();
			}
		}
	}

	else if (num == 2)
	{
		FUP(i, 0, 1)
		{
			queue<pair<int, int>> q;
			int ty = y;
			int tx = x;
			while (1)
			{
				ty += dy[i];
				tx += dx[i];
				if (ty >= N || tx >= M || ty < 0 || tx < 0) break;
				if (arr[ty][tx] == 6) break;
				if (arr[ty][tx] != 0) continue;
				arr[ty][tx] = 7;
				q.push({ ty, tx });
			}
			ty = y;
			tx = x;
			while (1)
			{
				ty += dy[i + 2];
				tx += dx[i + 2];
				if (ty >= N || tx >= M || ty < 0 || tx < 0) break;
				if (arr[ty][tx] == 6) break;
				if (arr[ty][tx] != 0) continue;
				arr[ty][tx] = 7;
				q.push({ ty, tx });
			}
			DFS(idx + 1, sum - q.size());
			while (!q.empty())
			{
				arr[q.front().first][q.front().second] = 0;
				q.pop();
			}
		}
	}

	else if (num == 3)
	{
		FUP(i, 0, 3)
		{
			queue<pair<int, int>> q;
			int ty = y;
			int tx = x;
			while (1)
			{
				ty += dy[i];
				tx += dx[i];
				if (ty >= N || tx >= M || ty < 0 || tx < 0) break;
				if (arr[ty][tx] == 6) break;
				if (arr[ty][tx] != 0) continue;
				arr[ty][tx] = 7;
				q.push({ ty, tx });
			}
			ty = y;
			tx = x;
			while (1)
			{
				ty += dy[(i + 1) % 4];
				tx += dx[(i + 1) % 4];
				if (ty >= N || tx >= M || ty < 0 || tx < 0) break;
				if (arr[ty][tx] == 6) break;
				if (arr[ty][tx] != 0) continue;
				arr[ty][tx] = 7;
				q.push({ ty, tx });
			}
			DFS(idx + 1, sum - q.size());
			while (!q.empty())
			{
				arr[q.front().first][q.front().second] = 0;
				q.pop();
			}
		}
	}

	else if (num == 4)
	{
		FUP(i, 0, 3)
		{
			queue<pair<int, int>> q;
			int ty = y;
			int tx = x;
			while (1)
			{
				ty += dy[i];
				tx += dx[i];
				if (ty >= N || tx >= M || ty < 0 || tx < 0) break;
				if (arr[ty][tx] == 6) break;
				if (arr[ty][tx] != 0) continue;
				arr[ty][tx] = 7;
				q.push({ ty, tx });
			}
			ty = y;
			tx = x;
			while (1)
			{
				ty += dy[(i + 1) % 4];
				tx += dx[(i + 1) % 4];
				if (ty >= N || tx >= M || ty < 0 || tx < 0) break;
				if (arr[ty][tx] == 6) break;
				if (arr[ty][tx] != 0) continue;
				arr[ty][tx] = 7;
				q.push({ ty, tx });
			}
			ty = y;
			tx = x;
			while (1)
			{
				ty += dy[(i + 2) % 4];
				tx += dx[(i + 2) % 4];
				if (ty >= N || tx >= M || ty < 0 || tx < 0) break;
				if (arr[ty][tx] == 6) break;
				if (arr[ty][tx] != 0) continue;
				arr[ty][tx] = 7;
				q.push({ ty, tx });
			}
			DFS(idx + 1, sum - q.size());
			while (!q.empty())
			{
				arr[q.front().first][q.front().second] = 0;
				q.pop();
			}
		}
	}

	else if (num == 5)
	{
		queue<pair<int, int>> q;
		FUP(i, 0, 3)
		{
			int ty = y;
			int tx = x;
			while (1)
			{
				ty += dy[i];
				tx += dx[i];
				if (ty >= N || tx >= M || ty < 0 || tx < 0) break;
				if (arr[ty][tx] == 6) break;
				if (arr[ty][tx] != 0) continue;
				arr[ty][tx] = 7;
				q.push({ ty, tx });
			}
		}
		DFS(idx + 1, sum - q.size());
		while (!q.empty())
		{
			arr[q.front().first][q.front().second] = 0;
			q.pop();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, M - 1)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0) answer++;
			if (arr[i][j] != 0 && arr[i][j] != 6)
			{
				cctv[cnt] = { i, j };
				cnt++;
			}
		}
	}

	DFS(0, answer);
	cout << answer;
	

	return 0;
}