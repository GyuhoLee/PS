#include <bits/stdc++.h>
using namespace std;

int T, N, K;
bool visited[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		int no = -1;
		memset(visited, false, sizeof(visited));
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> K;
			bool ok = false;
			for (int j = 0; j < K; j++)
			{
				int temp;
				cin >> temp;
				if (ok) continue;
				if (!visited[temp])
				{
					visited[temp] = true;
					ok = true;
				}
			}
			if (!ok) no = i;
		}
		if (no == -1)
		{
			cout << "OPTIMAL\n";
			continue;
		}
		for (int i = N; i > 0; i--)
		{
			if (!visited[i])
			{
				cout << "IMPROVE\n" << no << ' ' << i << '\n';
				break;
			}
		}
	}

	return 0;
}