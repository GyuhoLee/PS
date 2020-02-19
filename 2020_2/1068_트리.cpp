#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int root, del;
int answer = 0;
vector<int> node[50];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp == -1) root = i;
		else node[temp].push_back(i);
	}
	cin >> del;
}

void solve(int nod)
{
	if (nod == del) return;
	if (node[nod].size() == 0)
	{
		answer++;
		return;
	}
	if (node[nod].size() == 1 && node[nod][0] == del) answer++;
	for (auto i : node[nod]) solve(i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve(root);
	cout << answer;

	return 0;
}