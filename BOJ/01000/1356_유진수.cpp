#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	string answer = "NO";
	for (int i = 0; i < str.size() - 1; i++)
	{
		int A = 1, B = 1;
		for (int j = 0; j <= i; j++)
		{
			A *= (str[j] - '0');
		}
		for (int j = i + 1; j < str.size(); j++)
		{
			B *= (str[j] - '0');
		}
		if (A == B)
		{
			answer = "YES";
			break;
		}
	}
	cout << answer;

	return 0;
}