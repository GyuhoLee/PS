#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int sum = 0;
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 5);
	printf("%d\n%d", sum / 5, arr[2]);


	return 0;
}