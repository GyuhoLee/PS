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
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	string answer = "";
	for (auto s : str)
	{
		if (s < 'Z') answer += char(s + 32);
		else answer += char(s - 32);
	}
	cout << answer;

	return 0;
}