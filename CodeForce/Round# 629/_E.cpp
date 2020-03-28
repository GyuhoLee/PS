#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[200001];
int depth[200001];
bool visited[200001];
int group[200001];
vector<int> v[200001];

void setting(int num)
{
	int i = 1;
	for (auto s : v[num])
	{
		if (!visited[s])
		{
			if (num == 1) group[s] = i;
			else group[s] = group[num];
			depth[s] = depth[num] + 1;
			parent[s] = num;
			visited[s] = true;
			setting(s);
		}
		i++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(visited, false, sizeof(visited));
	visited[1] = true;
	group[1] = 0;
	parent[1] = 0;
	depth[1] = 0;
	setting(1);
	while (M--)
	{
		int K;
		cin >> K;
		int max_depth = 0;
		int max_num = 1;
		vector<int> temp;
		set<int> groupCnt;
		set<int> SS;
		bool overTwo = false;
		bool found = false;
		for (int i = 0; i < K; i++)
		{
			int num;
			cin >> num;
			temp.push_back(num);
			
			if (!SS.count(group[num]) && groupCnt.count(group[num]))
			{
				if (overTwo) found = true;
				SS.insert(group[num]);
				overTwo = true;
			}
			else groupCnt.insert(group[num]);
			if (max_depth < depth[num])
			{
				max_depth = depth[num];
				max_num = num;
			}
		}
		if (found)
		{
			cout << "NO\n";
			continue;
		}
		if (max_depth >= N - 3)
		{
			cout << "YES\n";
			continue;
		}
		set<int> S;
		S.insert(max_num);
		while (max_num != 0)
		{
			S.insert(parent[max_num]);
			max_num = parent[max_num];
		}
		bool ok = true;
		for (auto s : temp)
		{
			if (S.count(parent[s]) == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}