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
	
	int arr[6] = { 1, 1, 2, 2, 2, 8 };
	int arr2[6];
	int arr3[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> arr2[i];
		arr3[i] = arr[i] - arr2[i];
	}
	for (int i = 0; i < 6; i++)
		cout << arr3[i] << ' ';

	return 0;
}