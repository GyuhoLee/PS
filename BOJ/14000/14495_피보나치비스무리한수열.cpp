#include <iostream>
using namespace std;

long long arr[117];
int N;

int main()
{
	arr[1] = arr[2] = arr[3] = 1;
	cin >> N;
	for (int i = 4; i <= N; i++)
		arr[i] = arr[i - 1] + arr[i - 3];
	cout << arr[N];

	return 0;
}