#include <iostream>
#include <algorithm>
using namespace std;

int H, W, arr[502], pre[502], post[502], ans = 0;

int main()
{
	cin >> H >> W;
	for (int i = 1; i <= W; i++)
	{
		cin >> arr[i];
		pre[i] = max(pre[i - 1], arr[i]);
	}
	for (int i = W; i >= 1; i--)
	{
		post[i] = max(post[i + 1], arr[i]);
	}
	for (int i = 2; i < W; i++)
	{
		int tmp = min(pre[i], post[i]) - arr[i];
		tmp > 0 ? ans += tmp : ans;
	}
	cout << ans;

	return 0;
}