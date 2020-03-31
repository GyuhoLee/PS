#include <bits/stdc++.h>
using namespace std;

int T, N;
int arr[1000];
int color[1000];
int num[11] = { 2, 3, 5, 7, 11, 13, 17,19, 23, 29, 31 };
int visited[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (arr[i] % num[j] == 0)
				{
					if (visited[j] == 0)
					{
						cnt++;
						visited[j] = cnt;
					}
					color[i] = visited[j];
					break;
				}
			}
		}
		cout << cnt << '\n';
		for (int i = 0; i < N; i++) cout << color[i] << ' ';
		cout << '\n';

	}

	return 0;
}