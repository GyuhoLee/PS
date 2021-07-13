#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int N, arr[100000], ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, greater<int>());
	for (int i = 0; i < N; i++)
	{
		if (i % 3 != 2) ans += arr[i];
	}
	cout << ans;
	
	return 0;
}