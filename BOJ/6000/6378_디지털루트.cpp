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
	
	string N;
	do
	{
		cin >> N;
		if (N[0] == '0') break;
		int temp = 0;
		for (auto s : N)
		{
			temp = temp + ((int)s - '0');
		}
		while (temp >= 10)
		{
			int answer = 0;
			while (temp > 0)
			{
				answer = answer + (temp % 10);
				temp /= 10;
			}
			temp = answer;
		}
		cout << temp << '\n';
	} while (N[0] != '0');

	return 0;
}