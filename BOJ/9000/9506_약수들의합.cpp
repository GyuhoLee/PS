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
	
	while (true)
	{
		int num;
		cin >> num;
		if (num == -1) break;
		vector<int> v;
		int sum = 1;
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				v.push_back(i);
				sum += i;
			}
		}
		if (sum == num)
		{
			printf("%d = 1", num);
			for (auto s : v) printf(" + %d", s);
			printf("\n");
		}
		else printf("%d is NOT perfect.\n", num);
	}

	return 0;
}