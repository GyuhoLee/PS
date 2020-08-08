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
	
	int arr[4];
	for (int i = 0; i < 4; i++) cin >> arr[i];
	sort(arr, arr + 4);
	cout << arr[0] * arr[2];

	return 0;
}