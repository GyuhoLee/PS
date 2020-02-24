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
		int arr[100];
		bool visited[100];
		memset(visited, false, sizeof(visited));
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			arr[i] = temp;
		}
		for (int i = 0; i < M; i++)
		{
			int temp;
			cin >> temp;
			temp--;
			visited[temp] = true;
		}
		bool can = true;
		for (int i = 0; i < N; i++)
		{
			bool connect = true;
			for (int j = i - 1; j >= 0; j--)
			{
				if (!visited[j]) connect = false;
				if (!connect)
				{
					if (arr[i] < arr[j])
					{
						can = false;
						break;
					}
				}
			}
			connect = true;
			for (int j = i; j < N - 1; j++)
			{
				if (!visited[j]) connect = false;
				if(!connect)
				{
					if (arr[i] > arr[j + 1])
					{
						can = false;
						break;
					}
				}
			}
		}
		
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}