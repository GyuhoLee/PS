#include <bits/stdc++.h>
using namespace std;

int N, T, P, ans = 0;
pair<int, int> arr[501];
int s[101];
vector<int> status;

int main()
{
	cin >> N >> T >> P;
	for (int i = 1; i <= N; i++) s[i] = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + T);

	int idx = 0, i = 900;
	while(i <= 2059)
	{
		auto iter = status.begin();
		while (iter != status.end())
		{
			if (s[*iter] == i)
			{
				iter = status.erase(iter);
			}
			else iter++;
		}
		while (idx < T && arr[idx].first == i)
		{
			if (arr[idx].first == arr[idx].second)
			{
				idx++;
				continue;
			}
			if (status.empty())
			{
				status.push_back(1);
				s[1] = arr[idx].second;
			}
			else
			{
				sort(status.begin(), status.end());
				int tmpidx = -1;
				int tmpnum = status[0] - 1;
				for (int i = 1; i < status.size(); i++)
				{
					if ((status[i] - status[i - 1]) / 2 > tmpnum)
					{
						tmpidx = i;
						tmpnum = (status[i] - status[i - 1]) / 2;
					}
				}
				if (N - status.back() > tmpnum)
				{
					status.push_back(N);
					s[N] = arr[idx].second;
				}
				else if (tmpidx == -1)
				{
					status.push_back(1);
					s[1] = arr[idx].second;
				}
				else
				{
					int tmp = status[tmpidx - 1] + tmpnum;
					status.push_back(tmp);
					s[tmp] = arr[idx].second;
				}
			}
			idx++;
		}
		if (s[P] <= i) ans++;
		i++;
		if (i % 100 == 60) i += 40;
	}
	cout << ans;

	return 0;
}