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

	long long int K, N;
	cin >> K >> N;
	long long int arr[10000];
	for (int i = 0; i < K; i++) cin >> arr[i];
	sort(arr, arr + K);
	int answer = 0;
	long long int low = 1, high = arr[K - 1];
	while (low <= high)
	{
		int mid = (low + high) / 2;
        if(!mid) break;
		long long int temp = 0;
		for (int i = 0; i < K; i++) temp += (arr[i] / mid);
		if (temp >= N)
		{
			low = mid + 1;
			answer = mid;
		}
		else high = mid - 1;
	}
	cout << answer;

	return 0;
}