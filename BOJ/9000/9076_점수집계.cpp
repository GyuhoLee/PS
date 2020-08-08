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
	
	int T;
	cin >> T;
	while (T--)
	{
		int arr[5];
		for (int i = 0; i < 5; i++) cin >> arr[i];
		sort(arr, arr + 5);
		if (arr[1] + 4 <= arr[3]) cout << "KIN\n";
		else cout << arr[1] + arr[2] + arr[3] << '\n';
	}

	return 0;
}