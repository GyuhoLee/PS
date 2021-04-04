#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, num, X, ans = 0;
	set<int> S;
	cin >> N;
	while (N--)
	{
		cin >> num;
		S.insert(num);
	}
	cin >> X;
	for (int n : S)
	{
		if (n > X / 2) break;
		if (X % 2 == 0 && n == X / 2) break;
		ans += S.count(X - n);
	}
	cout << ans;

	return 0;
}