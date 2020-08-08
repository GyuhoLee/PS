#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[2000][2000];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (arr[ny][nx] == 'W') arr[ny][nx] = 'B';
				else arr[ny][nx] = 'W';
			}
		}
	}
	cout << "1\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'W') cout << 2;
			else cout << 3;
		}
		cout << '\n';
	}


	return 0;
}