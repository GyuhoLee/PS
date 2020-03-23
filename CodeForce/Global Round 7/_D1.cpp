#include <bits/stdc++.h>
using namespace std;

int T;
string str;
string answer;
int cnt = 1;

void falen(int first, int second)
{
	int sum = second - first + 1;
	for (int i = first - 1; i >= 0; i--)
	{
		int j = 1;
		for (; second + j < str.size() && i - j >= 0; j++)
		{
			if (str[second + j] != str[i - j]) break;
		}
		if (cnt < sum + j - 1)
		{
			cnt = sum + j - 1;
			answer = str.substr(i - j, j - 1) + str.substr(first, sum + j - 1);
		}
	}
	for (int i = second + 1; i < str.size(); i++)
	{
		int j = 1;
		for (; first - j >= 0 && i + j < str.size(); j++)
		{
			if (str[first - j] != str[i + j]) break;
		}
		if (cnt < sum + j - 1)
		{
			cnt = sum + j - 1;
			answer = str.substr(first - j + 1, sum + j - 1) + str.substr(i, j - 1);
		}
	}
}

void solve(int num)
{
	for (int i = str.size() - 1; i >= num; i--)
	{
		bool ok = true;
		for (int j = 0; num + j <= i - j; j++)
		{
			if (str[num + j] != str[i - j])
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			falen(num, i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> str;
		answer = str[0];
		for (int i = 0; i < str.size(); i++)
		{
			solve(i);
		}
		cout << answer << "\n";
	}

	return 0;
}