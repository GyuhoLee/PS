#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(i, a, b) for(int i = a; i < b; i++)
#define MS(a, b) memset(a, b, sizeof(a))

int N, M;
int arr[50][50];
bool visited[50][50];
int answer;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void DFS(int y, int x)
{
	F(i, 0, 8)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] || !arr[ny][nx]) continue;
		visited[ny][nx] = true;
		DFS(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> M >> N;
		if (!N && !M) break;
		F(i, 0, N)
		{
			F(j, 0, M)
			{
				cin >> arr[i][j];
				visited[i][j] = false;
			}
		}
		answer = 0;
		F(i, 0, N)
		{
			F(j, 0, M)
			{
				if (!visited[i][j] && arr[i][j])
				{
					visited[i][j] = true;
					DFS(i, j);
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}
	

	return 0;
}