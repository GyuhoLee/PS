#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	int arr[200000];
	int visited[1000];
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	if (N > 1000)
	{
		cout << 0;
		return 0;
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		arr[i] %= K;
	}
	int answer = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				cout << 0;
				return 0;
			}
			int temp = arr[i] - arr[j];
			if (temp < 0) temp += K;
			answer *= temp;
			answer %= K;
			
		}
	}
	cout << answer;


	

	return 0;
}