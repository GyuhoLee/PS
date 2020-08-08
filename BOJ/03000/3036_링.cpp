#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0) return b;
	return GCD(b, a % b);
}

int main()
{
	int N;
	cin >> N;
	int arr[100];
	cin >> arr[0];
	for (int i = 1; i < N; i++)
	{
		cin >> arr[i];
		int temp = GCD(arr[i], arr[0]);
		printf("%d/%d\n", arr[0] / temp, arr[i] / temp);
	}
}