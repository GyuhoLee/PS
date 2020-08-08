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
	
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int temp = 0;
		while (N > 0)
		{
			if (N % 2) cout << temp << ' ';
			N >>= 1;
			temp++;
		}

		cout << '\n';
	}

	return 0;
}