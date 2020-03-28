#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int arr[50][50];
bool answer[50][50];

bool can(int y, int x)
{
	if (arr[y + 1][x + 1] && arr[y + 1][x] && arr[y][x + 1]) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		memset(answer, false, sizeof(answer));
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cin >> arr[i][j];
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < M - 1; j++)
			{
				if (arr[i][j] && can(i, j)) answer[i][j] = answer[i + 1][j] = answer[i][j + 1] = answer[i + 1][j + 1] = true;
			}
		}
		bool ok = true;
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < M - 1; j++)
			{
				if (arr[i][j] && !answer[i][j]) ok = false;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}