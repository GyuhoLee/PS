#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
vector<int> S;
vector<int> permut;

void input()
{
	S.clear();
	permut.clear();
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		S.push_back(temp);
	}
	for (int i = 0; i < 6; i++)
	{
		permut.push_back(1);
	}
	for (int i = 6; i < k; i++)
	{
		permut.push_back(0);
	}
}

void solve()
{
	do
	{
		for (int i = 0; i < k; i++)
		{
			if (permut[i])
			{
				cout << S[i] << ' ';
			}
		}
		cout << '\n';
	} while (prev_permutation(permut.begin(), permut.end()));
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		input();
		if (!k) break;
		solve();
	}

	return 0;
}