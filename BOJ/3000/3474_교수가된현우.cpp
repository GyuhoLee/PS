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
		int answer = 0;
		for (int i = 5; i <= N; i *= 5)
		{
			answer = answer + (N / i);
		}
		cout << answer << '\n';
	}

	return 0;
}