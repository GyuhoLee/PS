#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int total = 0;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			total += temp;
		}
		if (total > M) cout << M << '\n';
		else cout << total << '\n';
	}


	return 0;
}