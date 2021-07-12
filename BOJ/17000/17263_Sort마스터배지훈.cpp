#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[500000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cout << *max_element(arr, arr + N);

	return 0;
}