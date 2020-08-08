#include <bits/stdc++.h>
using namespace std;

int T, N;
pair<int, int> arr[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
		sort(arr, arr + N);
		int answer = 0;
		int minNum = INT_MAX;
		for (int i = 0; i < N; i++)
		{
			if (minNum > arr[i].second)
			{
				answer++;
				minNum = arr[i].second;
			}
		}
		cout << answer << '\n';
	}



	return 0;
}