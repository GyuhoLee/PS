#include <iostream>
#include <algorithm>
using namespace std;

int T, N, arr[10000], ans;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		ans = 0;
		for (int i = 0; i < N; i++) cin >> arr[i];
		sort(arr, arr + N);
		for (int i = 2; i < N; i++) ans = max(ans, arr[i] - arr[i - 2]);
		cout << ans << '\n';
	}
	

	return 0;
}