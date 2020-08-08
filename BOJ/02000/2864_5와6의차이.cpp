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

	string A, B;
	cin >> A >> B;
	pair<int, int> answer = make_pair(0, 0);
	int digit = 1;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (A[i] == '5') answer.first += (6 * digit);
		else answer.first += ((A[i] - '0') * digit);

		if (A[i] == '6') answer.second += (5 * digit);
		else answer.second += ((A[i] - '0') * digit);
		
		digit *= 10;
	}
	digit = 1;
	for (int i = B.size() - 1; i >= 0; i--)
	{
		if (B[i] == '5') answer.first += (6 * digit);
		else answer.first += ((B[i] - '0') * digit);

		if (B[i] == '6') answer.second += (5 * digit);
		else answer.second += ((B[i] - '0') * digit);

		digit *= 10;
	}
	cout << answer.second << ' ' << answer.first;


	return 0;
}