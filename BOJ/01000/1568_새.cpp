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
	int answer = 0;
	int i = 1;
	while (N != 0)
	{
		if (N < i) i = 1;
		N -= i;
		i++;
		answer++;
	}
	cout << answer;


	return 0;
}