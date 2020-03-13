#include <bits/stdc++.h>
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
		string str;
		cin >> str;
		int answer = 1;
		int cnt = 1;
		for (auto s : str)
		{
			if (s == 'L') cnt++;
			else
			{
				answer = max(cnt, answer);
				cnt = 1;
			}
		}
		answer = max(cnt, answer);
		cout << answer << "\n";
	}

	return 0;
}