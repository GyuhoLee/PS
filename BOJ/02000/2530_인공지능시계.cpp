#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	c += d;
	b += (c / 60);
	c %= 60;
	a += (b / 60);
	b %= 60;
	a %= 24;
	cout << a << ' ' << b << ' ' << c;

	return 0;
}