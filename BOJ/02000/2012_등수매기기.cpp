#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long N, arr[500001], ans;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) ans += abs(i - arr[i]);
	cout << ans;

	return 0;
}