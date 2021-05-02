#include <iostream>
#include <algorithm>
using namespace std;

int N, ans[1000000];
pair<int, int> arr[1000000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		arr[i].second = i;
		cin >> arr[i].first;
	}
	sort(arr, arr + N);
	int idx = 0;
	ans[arr[0].second] = 0;
	for (int i = 1; i < N; i++)
	{
		if (arr[i].first == arr[i - 1].first) ans[arr[i].second] = idx;
		else ans[arr[i].second] = ++idx;
	}
	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}