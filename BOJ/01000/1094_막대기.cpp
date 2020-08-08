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
	
	int N;
	cin >> N;
	int answer = 0;
	for (int i = 64; i > 0; i /= 2)
	{
		if (N / i)
		{
			answer++;
			N -= i;
		}
	}
	cout << answer;

	return 0;
}