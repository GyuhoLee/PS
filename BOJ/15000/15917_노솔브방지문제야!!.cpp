#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int Q;
set<ll> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll i = 1;
	for (; i <= (1 << 30); i *= 2)
		s.insert(i);
	s.insert(i);
	cin >> Q;
	while (Q--)
	{
		ll temp;
		cin >> temp;
		if (s.count(temp)) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}