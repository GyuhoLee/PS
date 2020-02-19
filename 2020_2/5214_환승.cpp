#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <queue>
using namespace std;

int N, K, M;
int k[1000];
int answer = -1;
bool visited[100001];
vector<int> v[100001];
vector<int> E[1000];
queue<pair<int, int>> q;

void input()
{
	memset(visited, false, sizeof(visited));
	cin >> N >> K >> M;
	for(int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int temp;
			cin >> temp;
			E[i].push_back(temp);
			v[temp].push_back(i);
		}
	}
}

void solve()
{
	visited[1] = true;
	q.push(make_pair(1, 1));
	while (!q.empty())
	{
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (node == N)
		{
			answer = cnt;
			return;
		}
		for (auto i : v[node])
		{
			for (auto j : E[i])
			{
				if (visited[j]) continue;
				visited[j] = true;
				q.push(make_pair(j, cnt + 1));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	cout << answer;
}