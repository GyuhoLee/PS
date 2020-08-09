#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	pair<int, int> str[500];
	for (int i = 0; i < 500; i++) str[i] = { -1,-1 };
	bool visited[100001];
	memset(visited, false, sizeof(visited));
	int i = 0;
	int cnt = 0;
	for (int j = 1; j < s.size() - 1; j++)
	{
		if (s[j] == ',') cnt++;
		else if (s[j] == '{')
		{
			i = j;
			cnt = 0;
		}
		else if (s[j] == '}')
		{
			str[cnt] = make_pair(i, j);
			cnt = 0;
		}
	}
	for (int i = 0; i < 500; i++)
	{
		if (str[i].first == -1) break;
		string before = "";
		for (int j = str[i].first + 1; j <= str[i].second; j++)
		{
			if (s[j] == ',' || s[j] == '}')
			{
				if (visited[stoi(before)]) before = "";
				else
				{
					answer.push_back(stoi(before));
					visited[stoi(before)] = true;
					break;
				}
			}
			else before += s[j];
		}
	}
	return answer;
}