#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, arr[100000];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, greater<int>());
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer = max(answer, i + 2 + arr[i]);
	}
	cout << answer;

	return 0;
}