#include <iostream>
#include <algorithm>
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
		int N;
		cin >> N;
		pair<int, int> arr[100];
		bool visited[201];
		for (int i = 0; i < N; i++) arr[i].second = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i].first;
			visited[arr[i].first] = true;
		}
		bool fail = false;
		int left = 0, right = 0;
		for (int i = 1; i <= 2 * N; i++)
		{
			if (visited[i]) left++;
			else right++;
			if (right > left)
			{
				fail = true;
				break;
			}
			if (!visited[i])
			{
				for (int j = 0; j < N; j++)
				{
					if (arr[j].second == 0 && arr[j].first < i)
					{
						arr[j].second = i;
						break;
					}
				}
			}

		}
		/*
		for (int k = 0; k < N; k++)
		{
			int minN = 2 * N + 1;
			int minI = 0;
			for (int i = 0; i < N; i++)
			{
				if (arr[i].second == 0 && arr[i].first < minN)
				{
					minI = i;
					minN = arr[i].first;
				}
			}
			int v = 0;
			for (int i = 1; i <=2 * N; i++)
			{
				if (!visited[i])
				{
					v = i;
					break;
				}
			}
			visited[v] = true;
			if (arr[minI].first > v)
			{
				fail = true;
				break;
			}
			arr[minI].second = v;
		}
		*/
		if (fail) cout << "-1\n";
		else
		{
			for (int i = 0; i < N; i++)
			{
				cout << arr[i].first << ' ' << arr[i].second << ' ';  
			}
			cout << '\n';
		}
	}

	return 0;
}