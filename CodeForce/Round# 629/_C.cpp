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
		string A = "1";
		string B = "1";
		int N;
		string str;
		cin >> N >> str;
		bool isBig = false;
		for (int i = 1; i < N; i++)
		{
			switch (str[i])
			{
			case '0':
				A += '0';
				B += '0';
				break;
			case '1':
				if (isBig)
				{
					A += '0';
					B += '1';
				}
				else
				{
					A += '1';
					B += '0';
					isBig = true;
				}
				break;
			default:
				if (isBig)
				{
					A += '0';
					B += '2';
				}
				else
				{
					A += '1';
					B += '1';
				}
				break;
			}
		}
		cout << A << '\n' << B << '\n';
	}

	return 0;
}