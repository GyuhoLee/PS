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
		ll a, b;
		cin >> a >> b;
		if (b > a)
		{
			cout << b - a << '\n';
		}
		else
		{
			cout << (b - (a % b)) % b << '\n';
		}
	}

	return 0;
}