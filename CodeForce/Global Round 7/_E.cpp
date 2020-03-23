#include <bits/stdc++.h>
using namespace std;

int N;
int P[300001];
int Q[300001];
int arr[300001];
bool visited[300001];
set<int, greater<int>> S;
set<int> mod;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
		arr[P[i]] = i;
		S.insert(i);
		mod.insert(i);
	}
	cin >> Q[1];
	cout << N << ' ';
	int max_num = 1;
	for (int i = 2; i <= N; i++)
	{
		if(max_num < Q[i - 1]) Q[i - 1] = max_num;
		cin >> Q[i];
		if (*mod.begin() > Q[i - 1])
		{
			Q[i - 1] = *mod.begin();
		}
		for (auto s : S)
		{
			if (arr[s] <= Q[i - 1])
			{
				S.erase(s);
				mod.erase(arr[s]);
				visited[arr[s]] = true;
				break;
			}
		}
		cout << *S.begin() << ' ';
	}

	return 0;
}