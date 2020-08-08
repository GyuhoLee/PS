#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
int arr[300][300];
bool visited[300][300];
int year = 0;

void solve()
{
	queue<pair<int, pair<int, int>>> q;
	FUP(i, 1, N - 2)
	{
		FUP(j, 1, M - 2)
		{
			if (arr[i][j] == 0) continue;
			int cnt = 0;
			FUP(k, 0, 3)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (arr[ny][nx] == 0) cnt++;
			}
			if (cnt) q.push({ cnt,{i, j} });
		}
	}
	while (!q.empty())
	{
		int y = q.front().second.first;
		int x = q.front().second.second;
		int num = q.front().first;
		q.pop();
		arr[y][x] -= num;
		arr[y][x] = max(arr[y][x], 0);
	}
}

void DFS(int y, int x)
{
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny >= N - 1 || nx >= M - 1 || visited[ny][nx] || !arr[ny][nx]) continue;
		visited[ny][nx] = true;
		DFS(ny, nx);
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
		}
	}

	while (1)
	{
		year++;
		solve();
		int cnt = 0;
		MS(visited, false);
		FUP(i, 1, N - 1)
		{
			FUP(j, 1, M - 1)
			{
				if (!visited[i][j] && arr[i][j])
				{
					visited[i][j] = true;
					cnt++;
					DFS(i, j);
				}
			}
		}
		if (cnt == 0) break;
		else if (cnt == 1) continue;
		cout << year;
		return 0;
	}
	cout << 0;

	return 0;
}