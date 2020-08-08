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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		int chicken, leg;
		cin >> leg >> chicken;
		for (int i = 0; i <= chicken; i++)
		{
			if (i * 2 + (chicken - i) == leg)
			{
				cout << chicken - i << ' ' << i << '\n';
				break;
			}
		}
	}

	return 0;
}