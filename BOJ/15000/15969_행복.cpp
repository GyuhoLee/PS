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
	
	int maxT = -1;
	int minT = 1001;
	int N;
	cin >> N;
	while (N--)
	{
		int num;
		cin >> num;
		maxT = max(num, maxT);
		minT = min(num, minT);
	}
	cout << maxT - minT;

	return 0;
}