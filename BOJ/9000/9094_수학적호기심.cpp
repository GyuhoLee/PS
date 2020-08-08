#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		int answer = 0;
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if ((i * i + j * j + M) % (i * j) == 0) answer++;
			}
		}
		cout << answer << '\n';
	}
	

	return 0;
}