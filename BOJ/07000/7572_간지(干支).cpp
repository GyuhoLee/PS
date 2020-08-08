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
	
	int N;
	cin >> N;
	char c = 'I';
	int i = 6;
	int cT = N % 12;
	c += cT;
	if (c > 'L') c -= 12;
	int iT = N % 10;
	i += iT;
	if (i > 9) i -= 10;
	cout << c << i;

	return 0;
}