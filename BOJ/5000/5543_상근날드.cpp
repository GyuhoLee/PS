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
	
	int answer = -50;
	int a, b, c;
	cin >> a >> b >> c;
	answer += min(a, min(b, c));
	cin >> a >> b;
	answer += min(a, b);
	cout << answer;

	return 0;
}