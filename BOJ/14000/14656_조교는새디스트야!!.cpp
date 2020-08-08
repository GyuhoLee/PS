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

	int answer = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		if (temp != i) answer++;
	}
	cout << answer;

	return 0;
}