#include <bits/stdc++.h>
using namespace std;

int T, N;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> str;
		int answer = 1;
		string sAnswer = str;
		int i = 2;
		int j = N - 1;
		while (i <= N)
		{
			string temp;
			if ((i % 2 && N % 2 == 0) || (i % 2 == 0 && N % 2))
			{
				temp = str.substr(i - 1) + str.substr(0, i - 1);
			}
			else
			{
				temp = str.substr(i - 1);
				string temp2 = str.substr(0, i - 1);
				reverse(temp2.begin(), temp2.end());
				temp += temp2;
			}
			if (temp < sAnswer)
			{
				sAnswer = temp;
				answer = i;
			}
			i++;
		}
		cout << sAnswer << '\n' << answer << "\n";
	}

	return 0;
}