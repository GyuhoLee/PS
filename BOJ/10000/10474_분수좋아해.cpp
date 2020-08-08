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
	
	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a + b == 0) break;
		printf("%d %d / %d\n", a / b, a % b, b);
	}


	return 0;
}