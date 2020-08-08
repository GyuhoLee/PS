#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> arr[100000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tx, ty;
		cin >> tx >> ty;
		arr[i].second = tx;
		arr[i].first = ty;
	}
	
	sort(arr, arr + N);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", arr[i].second, arr[i].first);
	}

	return 0;
}