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
	int arr[10];
	int arr2[10];
	for (int i = 0; i < 10; i++) cin >> arr[i];
	sort(arr, arr + 10);
	for (int i = 0; i < 10; i++) cin >> arr2[i];
	sort(arr2, arr2 + 10);
	cout << arr[7] + arr[8] + arr[9] << ' ' << arr2[7] + arr2[8] + arr2[9];

	return 0;
}