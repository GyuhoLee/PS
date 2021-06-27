#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[1001], min_x = 2000, max_x = 0, l, h, ans;

int main()
{
	cin >> N;
	while (N--)
	{
		cin >> l >> h;
		arr[l] = h;
	}
	h = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (h < arr[i])
		{
			min_x = max_x = i;
			h = arr[i];
		}
		else if (h == arr[i]) max_x = i;
	}
	for (int i = min_x; i <= max_x; i++) arr[i] = h;
	for (int i = 2; i < min_x; i++) arr[i] = max(arr[i], arr[i - 1]);
	for (int i = 999; i > max_x; i--) arr[i] = max(arr[i], arr[i + 1]);
	for (int i = 1; i <= 1000; i++) ans += arr[i];
	cout << ans;

	return 0;
}