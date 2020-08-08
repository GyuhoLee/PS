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

	int T;
	cin >> T;
	while (T--)
	{
		int arr[10];
		for (int i = 0; i < 10; i++) cin >> arr[i];
		sort(arr, arr + 10);
		cout << arr[7] << '\n';
	}

	return 0;
}