#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> arr(1001, 0);
vector<int> arr2(1001, 0);

int main()
{
	scanf_s("%d", &n);
	scanf_s("%d", &k);
	for (int i = 1; i <= n; i++) scanf_s("%d", &arr2[i]);
	arr[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = arr2[i]; j <= k; j++)
		{
			arr[j] += arr[j - arr2[i]];
		}
	}
	printf_s("%d", arr[k]);

	return 0;
}