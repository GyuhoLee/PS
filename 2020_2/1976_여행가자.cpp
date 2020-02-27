#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[200][200];
int way[1000];
vector<int> road[200];
bool visited[200];
bool answer[200][200];
bool can = true;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j]) road[i].push_back(j);
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> way[i];
		way[i]--;
	}
}

void check()
{
	for (int i = 0; i < N; i++)
	{
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int node = q.front();
			answer[i][node] = true;
			q.pop();
			for (auto s : road[node])
			{
				if (!visited[s])
				{
					q.push(s);
					visited[s] = true;
				}
			}
		}
	}
}

void output()
{
	for (int i = 0; i < M - 1; i++)
	{
		if (!answer[way[i]][way[i + 1]])
		{
			can = false;
			break;
		}
	}
	if (can) cout << "YES";
	else cout << "NO";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	check();
	output();

	return 0;
}