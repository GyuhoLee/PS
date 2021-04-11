#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	set<int> S;
	vector<int> V[5001];
	int N, x, y, ans = 0;
	cin >> N;
	while (N--)
	{
		cin >> x >> y;
		S.insert(y);
		V[y].push_back(x);
	}
	for (int c : S)
	{
		sort(V[c].begin(), V[c].end());
		for (int i = 0; i < V[c].size(); i++)
		{
			int num = 9999999;
			if (i != 0) num = V[c][i] - V[c][i - 1];
			if (i != V[c].size() - 1) num = min(num, V[c][i + 1] - V[c][i]);
			ans += num;
		}
	}
	cout << ans;

	return 0;
}