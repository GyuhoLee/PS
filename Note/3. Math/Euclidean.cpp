#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
	if (x < y) swap(x, y);
	int rest;
	while (y)
	{
		rest = x % y;
		x = y;
		y = rest;
	}
	return x;
}

int gcd(int x, int y)
{
	if (!y) return x;
	else return gcd(y, x % y);
}