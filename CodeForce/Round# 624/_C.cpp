#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		string str;
		int arr[200000];
		int answer[26];
		memset(answer, 0, sizeof(answer));
		cin >> str;
		for (int i = 0; i < M; i++)
		{
			cin >> arr[i];
			arr[i]--;
		}
		sort(arr, arr + M);
		int before = 0;
		for (int i = 0; i <= arr[M - 1]; i++)
		{
			for (int j = before; j < M; j++)
			{
				if(arr[j] >= i)
				{
					before = j;
					break;
				}
			}
			answer[str[i] - 'a'] += M + 1 - before;
		}
		for (int i = arr[M - 1] + 1; i < N; i++)
		{
			answer[str[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) cout << answer[i] << ' ';
		cout << '\n';

	}

	return 0;
}