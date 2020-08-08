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
#include <stdlib.h>
#include <sstream>
using namespace std;

int three(int n)
{
	return n * n * n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector < pair<pair<int, int>, pair<int, int>>> v;
	for (int i = 4; i <= 100; i++)
	{
		for (int j = 2; j < i; j++)
		{
			for (int k = 2; k <= j; k++)
			{
				for (int l = 2; l <= k; l++)
				{
					if (three(i) == three(j) + three(k) + three(l))
					{
						v.push_back(make_pair(make_pair(i, l), make_pair(k, j)));
					}
				}
			}
		}
	}
	sort(v.begin(), v.end());
	for (auto s : v)
	{
		cout << "Cube = " << s.first.first << ", Triple = (" << s.first.second << "," << s.second.first << "," << s.second.second << ")\n";
	}

	return 0;
}