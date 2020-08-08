#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>>
using namespace std;

int N, M;
int arr[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> permut;
int answer = INT_MAX;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			switch (arr[i][j])
			{
			case 1:
				house.push_back(make_pair(i, j));
				break;
			case 2:
				chicken.push_back(make_pair(i, j));
				break;
			}
		}
	}
	for (int i = 0; i < chicken.size() - M; i++)
	{
		permut.push_back(0);
	}
	for (int i = 0; i < M; i++)
	{
		permut.push_back(1);
	}
}

int distance(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve()
{
	do
	{
		int sum = 0;
		for (auto hIter : house)
		{
			int temp = INT_MAX;
			for (int i = 0; i < chicken.size(); i++)
			{
				if (permut[i])
				{
					temp = min(temp, distance(hIter, chicken[i]));
				}
			}
			sum += temp;
		}
		answer = min(sum, answer);
	} while (next_permutation(permut.begin(), permut.end()));
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
