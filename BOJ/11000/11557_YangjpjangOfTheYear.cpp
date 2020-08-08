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
		string answer;
		int maxT = -1;
		int N;
		cin >> N;
		while (N--)
		{
			string temp;
			int num;
			cin >> temp >> num;
			if (num > maxT)
			{
				maxT = num;
				answer = temp;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}