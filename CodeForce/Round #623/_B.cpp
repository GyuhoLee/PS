#include <iostream>
#include <algorithm>
#include <string>
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
		int a, b, p;
		cin >> a >> b >> p;
		string str;
		cin >> str;
		char before = str[str.size() - 2];
		if ((before == 'A' && a > p) || (before == 'B' && b > p))
		{
			cout << str.size() << '\n';
			continue;
		}
		else
		{
			if (before == 'A') p -= a;
			else p -= b;
		}
		int answer = 1;
		for (int i = str.size() - 3; i >= 0; i--)
		{
			if (before == str[i]) continue;
			before = str[i];
			if ((before == 'A' && a > p) || (before == 'B' && b > p))
			{
				answer = i + 2;
				break;
			}
			else
			{
				if (before == 'A') p -= a;
				else p -= b;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}