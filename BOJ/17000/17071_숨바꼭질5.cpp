#include <bits/stdc++.h>
using namespace std;

int N, K;
int go[1000];
queue<pair<int, int>> q;
int visited[500001][2];
int answer = -1;

void BFS()
{
	for (int i = 0; i <= 500000; i++)
	{
		visited[i][0] = -1;
		visited[i][1] = -1;
	}
	q.push({ N, 0 });
	visited[N][0] = 0;
	while (!q.empty())
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (K + go[cnt] > 500000) continue;
		if (cnt >= 999) continue;
		if (num * 2 < 500001 && visited[num * 2][(cnt + 1) % 2] == -1)
		{
			q.push({ num * 2, cnt + 1 });
			visited[num * 2][(cnt + 1) % 2] = cnt + 1;
		}
		if (num + 1 < 500001 && visited[num + 1][(cnt + 1) % 2] == -1)
		{
			q.push({ num + 1, cnt + 1 });
			visited[num + 1][(cnt + 1) % 2] = cnt + 1;
		}
		if (num - 1 >= 0 && visited[num - 1][(cnt + 1) % 2] == -1)
		{
			q.push({ num - 1, cnt + 1 });
			visited[num - 1][(cnt + 1) % 2] = cnt + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	go[0] = 0;
	for (int i = 1; i < 1000; i++) go[i] = go[i - 1] + i;
	BFS();
	for (int i = 0; i < 1000; i++)
	{
		if (K + go[i] > 500000) break;
		if (visited[K + go[i]][i % 2] != -1 && visited[K + go[i]][i % 2] <= i)
		{
			cout << i;
			return 0;
		}
	}

	cout << -1;

	return 0;
}