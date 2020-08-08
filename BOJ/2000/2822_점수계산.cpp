#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	pair<int, int> arr[8];
	for (int i = 1; i < 9; i++)
	{
		int N;
		cin >> N;
		arr[i - 1].first = N;
		arr[i - 1].second = i;
	}
	sort(arr, arr + 8);
	int answer = 0;
	vector<int> arr2;
	for (int i = 3; i < 8; i++)
	{
		answer += arr[i].first;
		arr2.push_back(arr[i].second);
	}
	sort(arr2.begin(), arr2.end());
	printf("%d\n", answer);
	for(int i = 0; i < 5; i++)
		printf("%d ", arr2[i]);

	return 0;
}