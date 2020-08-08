#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int arr[101];
	for (int i = 1; i <= N; i++) arr[i] = i;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		swap(arr[a], arr[b]);
	}
	for (int i = 1; i <= N; i++) cout << arr[i] << ' ';

	return 0;
}