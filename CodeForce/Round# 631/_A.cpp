#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(i, a, b) for(int i = a; i < b; i++)
#define MS(a, b) memset(a, b, sizeof(a))

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N, X;
		cin >> N >> X;
		bool visited[202];
		MS(visited, false);
		while (N--)
		{
			int temp;
			cin >> temp;
			visited[temp] = true;
		}
		int i = 1;
		while (X)
		{
			if (visited[i])
			{
				i++;
				continue;
			}
			visited[i] = true;
			i++;
			X--;
		}
		F(i, 1, 202)
		{
			if (!visited[i])
			{
				cout << i - 1 << '\n';
				break;
			}
		}
	}

	return 0;
}