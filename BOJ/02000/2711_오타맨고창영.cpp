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
		int num;
		string str;
		cin >> num >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (i + 1 == num) continue;
			cout << str[i];
		}
		cout << '\n';
	}

	return 0;
}