#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

ll T, N, arr[1000001], big[1000001], ans, cnt, tmp;

int main()
{
	cin >> T;
	while (T--)
	{
		ans = cnt = tmp = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> arr[i];
		big[N] = arr[N];
		for (int i = N - 1; i >= 1; i--) big[i] = max(arr[i], big[i + 1]);
		for (int i = 1; i <= N; i++)
		{
			if (arr[i] < big[i])
			{
				cnt++;
				tmp += arr[i];
			}
			else
			{
				ans += (arr[i] * cnt - tmp);
				cnt = tmp = 0;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}