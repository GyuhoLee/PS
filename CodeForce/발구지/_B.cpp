#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	int arr[100];
	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		sort(arr, arr + N);
		for (int i = N - 1; i >= 0; i--) cout << arr[i] << ' ';
		cout << '\n';
	}

	return 0;
}