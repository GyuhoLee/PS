#include <bits/stdc++.h>
using namespace std;

int N, M;
int answer = 0;
bool visited[101];
vector<int> computer[101];

void find(int num)
{
	for (auto s : computer[num])
	{
		if (!visited[s])
		{
			answer++;
			visited[s] = true;
			find(s);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(visited, false, sizeof(visited));
	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
	visited[1] = true;
	find(1);
	cout << answer;
	

	return 0;
}