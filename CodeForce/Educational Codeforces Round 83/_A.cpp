#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int A, B;
		cin >> A >> B;
		if (A % B == 0) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}