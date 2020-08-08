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

	int N, R, C;
	cin >> N >> R >> C;
	R %= 2;
	C %= 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i % 2 == R)
			{
				if (j % 2 == C) cout << 'v';
				else cout << '.';
			}
			else
			{
				if (j % 2 == C) cout << '.';
				else cout << 'v';
			}
		}
		cout << '\n';
	}

	return 0;
}