#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
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

	int A = 0, B = 0;
	int N;
	cin >> N;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) A++;
		else if (a < b) B++;
	}
	cout << A << ' ' << B;
	return 0;
}