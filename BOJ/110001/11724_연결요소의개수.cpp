#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(i,j) for(int i = 1; i <= j; i++)
#define MS(a, b) memset(a, b, sizeof(a))

int N, M;
vector<int> v[1001];
bool visited[1001];
int answer = 0;

void DFS(int num)
{
	for (auto s : v[num])
	{
		if (!visited[s])
		{
			visited[s] = true;
			DFS(s);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(visited, false);
	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	F(i, N)
	{
		if (!visited[i])
		{
			answer++;
			visited[i] = true;
			DFS(i);
		}
	}
	cout << answer;

	return 0;
}