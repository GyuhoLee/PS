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

	int a, b, c;
	cin >> a >> b >> c;
	int d = c / 60;
	int e = c % 60;
	a += d;
	b += e;
	a += b / 60;
	b %= 60;
	a %= 24;
	cout << a << ' ' << b;

	return 0;
}