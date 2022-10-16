#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K, arr[1000];
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, greater<int>());
	cout << arr[K - 1];

	return 0;
}