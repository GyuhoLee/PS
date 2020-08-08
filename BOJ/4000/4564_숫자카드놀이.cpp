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
	
	while (1)
	{
		int num;
		cin >> num;
		if (!num) break;
		if (num < 10)
		{
			cout << num << '\n';
			continue;
		}
		int temp;
		do
		{
			cout << num << ' ';
			temp = 1;
			while (num)
			{
				temp = temp * (num % 10);
				num /= 10;
			}
			num = temp;
		} while (temp >= 10);
		cout << num << '\n';
	}

	return 0;
}