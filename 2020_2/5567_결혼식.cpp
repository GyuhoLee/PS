#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v[501];
int visited[501];
int answer = 0;

void input()
{
	memset(visited, false, sizeof(visited));
	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = true;
}

void solve(int num)
{
	for (auto i : v[num])
	{
		if (visited[i]) continue;
		visited[i] = true;
		answer++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	for (auto i : v[1])
	{
		if (visited[i]) answer--;
		visited[i] = true;
		answer++;
		solve(i);
	}
	cout << answer;

	return 0;
}