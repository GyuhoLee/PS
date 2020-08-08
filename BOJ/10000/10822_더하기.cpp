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
	
	string str;
	cin >> str;
	vector<string> v;
	string temp = "";
	for (auto s : str)
	{
		if (s == ',')
		{
			v.push_back(temp);
			temp = "";
		}
		else temp += s;
	}
	v.push_back(temp);
	int answer = 0;
	for (auto s : v)
	{
		answer += atoi(s.c_str());
	}
	cout << answer;
	
	

	return 0;
}