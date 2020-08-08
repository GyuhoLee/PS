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
	
	int answer = 0;
	int now = 0;
	for (int i = 0; i < 10; i++)
	{
		int A, B;
		cin >> A >> B;
		now = now - A + B;
		answer = max(answer, now);
	}
	cout << answer;

	return 0;
}