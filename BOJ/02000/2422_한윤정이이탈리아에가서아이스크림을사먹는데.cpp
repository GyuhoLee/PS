#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, M, ans = 0, a, b;
set<int> S[201];


int main()
{
	cin >> N >> M;
	while (M--)
	{
		cin >> a >> b;
		if (a > b) swap(a, b);
		S[a].insert(b);
	}
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = i + 1; j <= N - 1; j++)
		{
			if (S[i].count(j)) continue;
			for (int k = j + 1; k <= N; k++)
			{
				if (S[i].count(k) || S[j].count(k)) continue;
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}