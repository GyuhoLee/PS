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

	int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d;
	cin >> e >> f >> g >> h;
	int i = a + b + c + d;
	int j = e + f + g + h;
	cout << max(i, j);

	return 0;
}