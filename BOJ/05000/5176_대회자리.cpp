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
		bool visited[501];
		memset(visited, false, sizeof(visited));
		int P, M;
		cin >> P >> M;
		int answer = 0;
		while (P--)
		{
			int temp;
			cin >> temp;
			if (visited[temp]) answer++;
			visited[temp] = true;
		}
		cout << answer << '\n';
	}
	

	return 0;
}