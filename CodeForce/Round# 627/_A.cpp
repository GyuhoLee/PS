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
		int N, arr[100];
		cin >> N;
		bool ok = true;
		cin >> arr[0];
		for (int i = 1; i < N; i++)
		{
			cin >> arr[i];
			if (arr[0] % 2 != arr[i] % 2) ok = false;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}