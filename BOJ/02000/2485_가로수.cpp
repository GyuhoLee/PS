#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[100000];

int gcd(int x, int y)
{
	if (!y) return x;
	else return gcd(y, x % y);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	int num = arr[1] - arr[0];
	for (int i = 2; i < N; i++) num = gcd(num, arr[i] - arr[i - 1]);
	cout << (arr[N - 1] - arr[0] + num) / num - N;


	return 0;
}