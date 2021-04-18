#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	while (1)
	{
		int N, P;
		cin >> N;
		if (!N) break;
		cin >> P;
		vector<int> v;
		if (P % 2 == 0) v.push_back(--P);
		else v.push_back(P + 1);
		v.push_back(N - P);
		v.push_back(N - P + 1);
		sort(v.begin(), v.end());
		for (int num : v) cout << num << ' ';
		cout << '\n';
	}
	return 0;
}