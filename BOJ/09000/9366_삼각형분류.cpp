#include <iostream>
#include <algorithm>
using namespace std;

int T, arr[3];

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);
		string ans = "";
		if (arr[0] + arr[1] <= arr[2]) ans = "invalid!";
		else if (arr[0] == arr[2]) ans = "equilateral";
		else if (arr[0] == arr[1] || arr[1] == arr[2]) ans = "isosceles";
		else ans = "scalene";
		cout << "Case #" << i << ": " << ans << '\n';
	}

	return 0;
}