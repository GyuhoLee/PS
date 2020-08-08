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
	
	int N, a, b;
	int answer = 0;
	cin >> N;
	while (N--)
	{
		cin >> a >> b;
		answer += (b % a);
	}
	cout << answer;

	return 0;
}