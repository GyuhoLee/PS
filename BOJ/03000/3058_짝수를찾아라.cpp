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
		int answer = 0;
		int minT = 101;
		for (int i = 0; i < 7; i++)
		{
			int temp;
			cin >> temp;
			if (temp % 2 == 0)
			{
				minT = min(minT, temp);
				answer += temp;
			}
		}
		cout << answer << ' ' << minT << '\n';
	}

	return 0;
}