#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	string str;
	cin >> N >> str;
	if (str.size() % 2 == 1)
	{
		cout << -1;
		return 0;
	}
	int left = 0;
	int right = 0;
	for (auto s : str)
	{
		if (s == '(') left++;
		else right++;
	}
	if (left != right)
	{
		cout << -1;
		return 0;
	}
	int answer = 0;
	int j = 0;
	bool no = false;
	left = 0;
	right = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') left++;
		else right++;
		if (!no && right > left)
		{
			j = i;
			no = true;
		}
		if (no && left == right)
		{
			left = 0;
			right = 0;
			answer += i - j + 1;
			no = false;
		}
	}
	cout << answer;

	return 0;
}