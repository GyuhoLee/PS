#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int n, x, y;
		cin >> n >> x >> y;
		int sum = x + y;
		int first;
		if (1 + n > sum || n == 1) first = 1;
		else if (x + y == n + n) first = n;
		else first = x + y + 1 - n;
		cout << first << ' ' << min(n, x + y - 1) << '\n';
	}

	return 0;
}