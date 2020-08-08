#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pair<int, pair<int, int>> arr[100];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
	}
	sort(arr, arr + N, greater<pair<int, pair<int, int>>>());
	int nation = 0;
	if (arr[0].second.first == arr[1].second.first) nation = arr[0].second.first;
	cout << arr[0].second.first << ' ' << arr[0].second.second << '\n';
	cout << arr[1].second.first << ' ' << arr[1].second.second << '\n';
	for (int i = 2; i < N; i++)
	{
		if (arr[i].second.first == nation) continue;
		cout << arr[i].second.first << ' ' << arr[i].second.second << '\n';
		break;
	}
	

	return 0;
}