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
	
	int answer = 1;
	int M;
	cin >> M;
	int a, b;
	while (M--)
	{
		cin >> a >> b;
		if (answer == a)
		{
			answer = b;
		}
		else if (answer == b)
		{
			answer = a;
		}
	}
	cout << answer;

	return 0;
}