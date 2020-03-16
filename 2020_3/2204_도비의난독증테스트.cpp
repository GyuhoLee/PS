#include <bits/stdc++.h>
using namespace std;

int N;
string str[1000];
pair<string, int> temp[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1)
	{
		cin >> N;
		if (!N) break;
		for (int i = 0; i < N; i++)
		{
			cin >> str[i];
			temp[i] = { str[i], i };
			for (int j = 0; j < temp[i].first.length(); j++)
			{
				if (temp[i].first[j] < 'a') temp[i].first[j] += (int)('a' - 'A');
			}
		}
		sort(temp, temp + N);
		cout << str[temp[0].second] << '\n';
	}

	return 0;
}

