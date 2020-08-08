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

	int a = 100, b = 100;
	int N;
	cin >> N;
	while (N--)
	{
		cin >> a >> b;
		cout << 2 - a + b << '\n';
	}

	return 0;
}