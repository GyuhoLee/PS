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

int sum = 0;
int answer = 0;
int arr[9];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> sum;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		answer += arr[i];
	}
	cout << sum - answer;

	return 0;
}