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

bool isM(char c)
{
	if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (true)
	{
		string str;
		cin >> str;
		if (str == "end") break;
		bool have = false;
		bool three = true;
		bool two = true;

		if (isM(str[0]))
		{
			have = true;
		}
		for (int i = 1; i < str.size(); i++)
		{
			if (isM(str[i])) have = true;
			if (str[i] == str[i - 1] && str[i] != 'e' && str[i] != 'o')
			{
				two = false;
				break;
			}
			if (i >= 2)
			{
				if (isM(str[i - 1]) == isM(str[i - 2]) && isM(str[i - 1]) == isM(str[i]))
				{
					three = false;
					break;
				}
			}
		}
		if (have && two && three) cout << "<" << str << "> is acceptable.\n";
		else cout << "<" << str << "> is not acceptable.\n";
	}

	return 0;
}