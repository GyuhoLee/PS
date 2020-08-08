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
		int N;
		char C;
		cin >> N >> C;
		while (N--)
		{
			if (C == 'C')
			{
				char ch;
				cin >> ch;
				cout << (int)ch - 'A' + 1 << ' ';
			}
			else
			{
				int num;
				cin >> num;
				char temp = (char)num - 1 + 'A';
				cout <<  temp << ' ';
			}
		}
		cout << '\n';
	}
	

	return 0;
}