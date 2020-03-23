#include <bits/stdc++.h>
using namespace std;

int M, N;
int arr[1000][1000];
int no = 0;
int answer = 0;
set<pair<int, int>> S;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void input()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (!arr[i][j]) no++;
			if (arr[i][j] == 1) S.insert({ i, j });
		}
	}
				
}

void solve()
{
	while (no)
	{
		answer++;
		bool have = false;
		set<pair<int, int>> s;
		for (auto t : S)
		{
			int i = t.first;
			int j = t.second;
			have = true;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] != 0) continue;
				if (s.count({ ny, nx })) continue;
				no--;
				s.insert({ ny, nx });
			}
			arr[i][j] = 2;
		}
		for (auto t : s)
		{
			arr[t.first][t.second] = 1;
		}
		S.swap(s);
		if (!have) break;
	}
	if (no) cout << -1;
	else cout << answer;
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