#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N;
int arr[100][100];
bool visited[100][100];
int max_height = 0;
int answer = 0;

void DFS(int y, int x, int h)
{
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || arr[ny][nx] <= h || visited[ny][nx]) continue;
		visited[ny][nx] = true;
		DFS(ny, nx, h);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, N - 1)
		{
			cin >> arr[i][j];
			max_height = max(arr[i][j], max_height);
		}
	}

	FUP(h, 0, max_height - 1)
	{
		MS(visited, false);
		int cnt = 0;
		FUP(i, 0, N - 1)
		{
			FUP(j, 0, N - 1)
			{
				if (arr[i][j] > h && !visited[i][j])
				{
					DFS(i, j, h);
					cnt++;
				}
			}
		}
		answer = max(cnt, answer);
	}

	cout << answer;
	return 0;
}