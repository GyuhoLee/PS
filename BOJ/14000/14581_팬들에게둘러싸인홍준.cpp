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
	string fan = ":fan:";
	cin >> str;
	str = ":" + str + ":";
	cout << fan << fan << fan << '\n'
		<< fan << str << fan << '\n'
		<< fan << fan << fan;

	return 0;
}