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
	
	int N;
	int arr[1000];
	int dp[1000];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	sort(dp, dp + N);
	cout << dp[N - 1];

	return 0;
}