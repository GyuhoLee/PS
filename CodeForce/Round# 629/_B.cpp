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
		int N, K;
		cin >> N >> K;
		int i;
		for (i = 1; i <= N; i++)
		{
			if (K - i <= 0) break;
			K -= i;
		}
		int temp = N - i - 1;
		while (temp--) { cout << 'a'; }
		cout << 'b';
		for (int j = 0; j < i - K; j++) cout << 'a';
		cout << 'b';
		for (int j = 0; j < K - 1; j++) cout << 'a';
		cout << '\n';

	}

	return 0;
}