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
		int N;
		cin >> N;
		int arr[20];
		for (int i = 0; i < N; i++) cin >> arr[i];
		sort(arr, arr + N);
		cout << 2 * (arr[N - 1] - arr[0]) << '\n';
	}


	return 0;
}