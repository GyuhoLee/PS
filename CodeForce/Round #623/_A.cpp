#include <iostream>
#include <algorithm>
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
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		x++;
		y++;
		int arr[4] = { 0, 0, 0, 0 };
		arr[0] = b * (x - 1);
		arr[1] = a * (y - 1);
		arr[2] = a * (b - y);
		arr[3] = b * (a - x);
		int answer = max(arr[0], arr[1]);
		int answer2 = max(arr[2], arr[3]);
		cout << max(answer, answer2) << '\n';
	}
	return 0;
}