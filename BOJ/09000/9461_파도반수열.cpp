#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	long long int arr[101];
	arr[1] = arr[2] = arr[3] = 1;
	for (int i = 4; i < 101; i++)
		arr[i] = arr[i - 2] + arr[i - 3];
	while (T--)
	{
		int N;
		cin >> N;
		printf("%lld\n", arr[N]);
	}

	return 0;
}