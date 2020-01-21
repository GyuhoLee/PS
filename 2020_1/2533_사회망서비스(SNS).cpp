#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <vector>
using namespace std;

int N, a, b;
vector<int> v[1000001];
int visited[1000001][2];

void input()
{
	scanf_s("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		scanf_s("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

int rec(int node, int early, int prev)
{
	int answer = 0;
	if (visited[node][early] != -1) return visited[node][early];
	if (early)
	{
		answer++;
		for (auto iter = v[node].begin(); iter != v[node].end(); iter++)
		{
			if (*iter != prev)
			{
				answer += min(rec(*iter, 0, node), rec(*iter, 1, node));
			}
		}
	}
	else
	{
		for (auto iter = v[node].begin(); iter != v[node].end(); iter++)
		{
			if (*iter != prev)
			{
				answer += rec(*iter, 1, node);
			}
		}
	}
	visited[node][early] = answer;
	return answer;
}


int main()
{
	input();
	memset(visited, -1, sizeof(visited));
	int a = rec(1, 0, -1);
	memset(visited, -1, sizeof(visited));
	int b = rec(1, 1, -1);
	printf("%d", min(a,b));

	return 0;
}