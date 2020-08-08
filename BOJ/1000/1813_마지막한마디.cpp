#include <bits/stdc++.h>
using namespace std;

int N, cnt[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		cnt[temp]++;
	}
	for (int i = N; i >= 0; i--)
	{
		if (i == cnt[i])
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
	

	return 0;
}