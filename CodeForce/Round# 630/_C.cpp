#include <bits/stdc++.h>
using namespace std;

int T, N, K;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		cin >> str;
		str = 'a' + str;
		int answer = 0;
		for (int i = 1; i <= K / 2; i++)
		{
			int arr[26];
			memset(arr, 0, sizeof(arr));
			int total = 0;
			for (int j = 0; i + j <= N; j += K)
			{
				arr[str[i + j] - 'a']++;
				arr[str[j + K - i + 1] - 'a']++;
				total += 2;
			}
			sort(arr, arr + 26, greater<int>());
			answer += (total - arr[0]);
		}
		if (K % 2)
		{
			int i = K / 2 + 1;
			int arr[26];
			memset(arr, 0, sizeof(arr));
			int total = 0;
			for (int j = 0; i + j <= N; j += K)
			{
				arr[str[i + j] - 'a']++;
				total++;
			}
			sort(arr, arr + 26, greater<int>());
			answer += (total - arr[0]);
		}
		cout << answer << '\n';
	}

	return 0;
}