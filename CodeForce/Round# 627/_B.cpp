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
		int before = -1;
		int visited[5001];
		memset(visited, 0, sizeof(visited));
		int N;
		cin >> N;
		bool ok = false;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			if (visited[temp] == 1 && before != temp) ok = true;
			else if (visited[temp] > 1) ok = true;
			visited[temp]++;
			before = temp;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;
}