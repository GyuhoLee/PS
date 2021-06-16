#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int S, T, N;
pair<int, int> arr[200000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		if (pq.empty() || pq.top() > arr[i].first) pq.push(arr[i].second);
		else
		{
			pq.pop();
			pq.push(arr[i].second);
		}
	}
	cout << pq.size();


	return 0;
}