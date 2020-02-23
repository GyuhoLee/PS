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
		int a, b, c;
		cin >> a >> b >> c;
		int answer = 0;
		if (a)
		{
			a--;
			answer++;
		}
		if (b)
		{
			b--;
			answer++;
		}
		if (c)
		{
			c--;
			answer++;
		}
		if (a >= 3 && b >= 3 && c >= 3) answer = 7;
		else if (a >= 2 && b >= 2 && c >= 2) answer = 6;
		else if (a >= 1 && b >= 1 && c >= 1)
		{
			if (a >= 2 || b >= 2 || c >= 2) answer = 5;
			else answer = 4;
		}
		else
		{
			if (a && b) answer++;
			if (b && c) answer++;
			if (a && c) answer++;
		}
		cout << answer << '\n';
	}
	return 0;
}