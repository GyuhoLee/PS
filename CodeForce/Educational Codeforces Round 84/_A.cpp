#include <bits/stdc++.h>
using namespace std;

int T;
long long int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		if (N % 2 == K % 2 && K * K <= N) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}