#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[20000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	cout << arr[(N - 1) / 2];

	return 0;
}