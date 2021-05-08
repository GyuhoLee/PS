#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define ll long long

int main()
{
	int N;
	vector<ll> visited(31, 0);
	while (1)
	{
		cin >> N;
		if (!N) break;
		if (visited[N])
		{
			cout << visited[N] << '\n';
			continue;
		}
		ll arr[61][31][61];
		memset(arr, 0, sizeof(arr));
		arr[0][N][0] = 1;
		for (int i = 0; i < 2 * N; i++)
		{
			for (int j = 0; j <= N; j++)
			{
				for (int k = 0; k <= 2 * N; k++)
				{
					if (j) arr[i + 1][j - 1][k + 1] += arr[i][j][k];
					if (k) arr[i + 1][j][k - 1] += arr[i][j][k];
				}
			}
		}
		visited[N] = arr[2 * N][0][0];
		cout << visited[N] << '\n';
	}

	return 0;
}