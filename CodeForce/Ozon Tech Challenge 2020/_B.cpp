#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	int N = str.size();
	vector<int> v;
	for (int i = N / 2; i > 0; i--)
	{
		v.clear();
		int cnt = 0;
		int cnt2 = 0;
		char ch = '(';
		int min_num = -1;
		for (int j = 0; j < N; j++)
		{
			if (str[j] == ch)
			{
				cnt++;
				v.push_back(j);
				if (cnt == i)
				{
					min_num = j;
					break;
				}
			}
		}
		ch = ')';
		if (min_num == -1) continue;
		for (int j = str.size() - 1; j > min_num; j--)
		{
			if (str[j] == ch)
			{
				cnt2++;
				v.push_back(j);
				if (cnt2 == i)
				{
					break;
				}
			}
		}

		if (cnt2 == i)
		{
			cout << "1\n" << i * 2 << '\n';
			sort(v.begin(), v.end());
			for (auto s : v)
			{
				cout << s + 1 << ' ';
			}
			return 0;
		}
	}
	cout << 0;

	return 0;
}