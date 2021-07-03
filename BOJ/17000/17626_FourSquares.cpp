#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[50001];

int main()
{
	arr[0] = 0;
	for (int i = 1; i <= 50000; i++)
	{
		arr[i] = arr[i - 1] + 1;
		for (int j = 2; j * j <= i; j++)
		{
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}
	cin >> n;
	cout << arr[n];

	return 0;
}