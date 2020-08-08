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
	
	int R, B;
	cin >> R >> B;
	for (int i = 3; i < 700000; i++)
	{
		for (int j = i; j < 700000; j++)
		{
			if (2 * (i + j) - 4 == R && (i - 2) * (j - 2) == B)
			{
				cout << j << ' ' << i;
				return 0;
			}
			if (2 * (i + j) - 4 >= R || (i - 2) * (j - 2) >= B) break;
		}
	}

	return 0;
}