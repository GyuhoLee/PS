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
	
	int Q[5] = { 0, 0, 0, 0, 0 };
	int N;
	cin >> N;
	while (N--)
	{
		int x, y;
		cin >> x >> y;
		if (x > 0)
		{
			if (y > 0) Q[1]++;
			else if (y < 0) Q[4]++;
			else Q[0]++;
		}
		else if (x < 0)
		{
			if (y > 0) Q[2]++;
			else if (y < 0) Q[3]++;
			else Q[0]++;
		}
		else Q[0]++;
	}
	for (int i = 1; i <= 4; i++)
	{
		cout << "Q" << i << ": " << Q[i] << '\n';
	}
	cout << "AXIS: " << Q[0];

	return 0;
}