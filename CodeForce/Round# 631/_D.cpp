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
		ll answer = 0;
		ll D, M;
		cin >> D >> M;
		ll idx = 1;
		ll num = 0;
		while (idx <= D)
		{
			answer = answer + (idx / 2) * (num + 1);
			answer %= M;
			idx *= 2;
			num = answer;
		}
		answer = answer + (D - (idx / 2) + 1) * (num + 1);
		answer %= M;
		cout << answer << '\n';
	}

	return 0;
}