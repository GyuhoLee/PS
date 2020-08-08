#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int answer[10001];
	answer[1] = 0;
	for (int i = 0; i <= 10000; i++)
	{
		for (int j = 1; j < 100; j++)
		{
			if (j + j * j <= i) answer[i] = j;
			else break;
		}
	}
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << answer[N] << '\n';
	}
	

	return 0;
}