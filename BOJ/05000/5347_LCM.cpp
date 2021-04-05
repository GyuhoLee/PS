#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll x, ll y)
{
	if (x < y) swap(x, y);
	ll rest;
	while (y)
	{
		rest = x % y;
		x = y;
		y = rest;
	}
	return x;
}

int main()
{
	ll N, A, B;
	cin >> N;
	while (N--)
	{
		cin >> A >> B;
		cout << A * B / gcd(A, B) << '\n';
	}

	return 0;
}