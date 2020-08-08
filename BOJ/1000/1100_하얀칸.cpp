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
	for (int i = 0; i < 64; i++)
	{
		char temp;
		cin >> temp;
		if (i / 8 % 2 == 0 && i % 2 == 0 && temp == 'F') answer++;
		if (i / 8 % 2 == 1 && i % 2 == 1 && temp == 'F') answer++;
	}
	cout << answer;

	return 0;
}