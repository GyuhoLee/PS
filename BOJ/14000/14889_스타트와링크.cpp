#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

int N;
int arr[20][20];
vector<int> team;
int answer = INT_MAX;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N / 2; i++)
	{
		team.push_back(0);
	}
	for (int i = 0; i < N / 2; i++)
	{
		team.push_back(1);
	}
	
}

void solve()
{
	do
	{
		int group[2] = { 0, 0 };
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (team[i] == team[j])
				{
					group[team[i]] += arr[i][j];
				}
			}
		}
		answer = min(answer, abs(group[0] - group[1]));
	} while (next_permutation(team.begin(), team.end()));
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();

	return 0;
}