#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
pair<int,string> arr[100000];

bool compare(pair<int,string> a, pair<int,string> b)
{
	return a.first < b.first;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	stable_sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++)
	{	
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}

	return 0;
}