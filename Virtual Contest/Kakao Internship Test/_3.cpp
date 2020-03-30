#include <string>
#include <vector>
#include <set>

using namespace std;
bool visited[8];
vector<int> ban[8];
int N;
set<int> S;

void DFS(int num)
{
	if (num == N)
	{
		int ret = 0;
		for (int i = 0; i < 8; i++)
		{
			if (visited[i])
			{
				ret += (1 << i);
			}
		}
		S.insert(ret);
		return;
	}
	for (auto n : ban[num])
	{
		if (visited[n]) continue;
		visited[n] = true;
		DFS(num + 1);
		visited[n] = false;
	}

}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	N = banned_id.size();
	for (int k = 0; k < banned_id.size(); k++)
	{
		for (int i = 0; i < user_id.size(); i++)
		{
			if (user_id[i].size() != banned_id[k].size()) continue;
			bool ok = true;
			for (int j = 0; j < user_id[i].size(); j++)
			{
				if (banned_id[k][j] == '*') continue;
				if (banned_id[k][j] != user_id[i][j])
				{
					ok = false;
					break;
				}
			}
			if (ok) ban[k].push_back(i);
		}
	}

	for (int i = 0; i < 8; i++) visited[i] = false;
	DFS(0);

	answer = S.size();
	return answer;
}