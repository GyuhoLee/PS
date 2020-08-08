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
	
	int answer = 0;
	char before = 'z';
	string word;
	cin >> word;
	for (char c : word)
	{
		if (c == before)
		{
			answer += 5;
		}
		else
		{
			answer += 10;
			before = c;
		}
	}
	cout << answer;

	return 0;
}