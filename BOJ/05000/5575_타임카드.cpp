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

	for (int i = 0; i < 3; i++)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		if (c > f)
		{
			f += 60;
			e--;
		}
		if (b > e)
		{
			e += 60;
			d--;
		}
		cout << d - a << ' ' << e - b << ' ' << f - c << '\n';
	}
	return 0;
}