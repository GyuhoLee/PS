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
		double num;
		cin >> num;
		string str;
		getline(cin, str);
		for (auto s : str)
		{
			switch (s)
			{
			case '@': num *= 3;
				break;
			case '#': num -= 7;
				break;
			case '%': num += 5;
				break;
			}
		}
		printf("%.2f\n", num);
	}

	return 0;
}