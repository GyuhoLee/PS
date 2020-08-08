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
	
	int day;
	cin >> day;
	int answer = 0;
	for (int i = 0; i < 5; i++)
	{
		int temp;
		cin >> temp;
		if (temp == day) answer++;
	}
	cout << answer;

	return 0;
}