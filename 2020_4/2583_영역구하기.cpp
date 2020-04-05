#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M, K;
bool arr[101][101];
bool visited[101][101];
int cnt;
vector<int> v;


void DFS(int y, int x)
{
	cnt++;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] || visited[ny][nx]) continue;
		visited[ny][nx] = true;
		DFS(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, false);
	MS(visited, false);
	cin >> N >> M >> K;
	while (K--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		FUP(i, a, c - 1)
		{
			FUP(j, b, d - 1)
			{
				arr[j][i] = true;
			}
		}
	}

	FUP(i, 0, N - 1)
	{
		FUP(j, 0, M - 1)
		{
			if (!arr[i][j] && !visited[i][j])
			{
				visited[i][j] = true;
				cnt = 0;
				DFS(i, j);
				v.push_back(cnt);
			}
		}
	}
	
	cout << v.size() << '\n';
	sort(ALL(v));
	for(auto s : v) cout << s << ' ';
	


	return 0;
}