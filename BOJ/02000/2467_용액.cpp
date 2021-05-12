#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N, arr[100000], tmp = 2e9 + 7;;
pair<int, int> ans;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int l = 0, r = N - 1;
	while (l < r)
	{
		int sum = abs(arr[l] + arr[r]);
		if (sum < tmp)
		{
			tmp = sum;
			ans = { arr[l], arr[r] };
		}
		if (arr[l] + arr[r] < 0) l++;
		else r--;
	}
	cout << ans.first << ' ' << ans.second;

	return 0;
}