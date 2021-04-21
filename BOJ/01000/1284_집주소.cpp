#include <iostream>
#include <string>
using namespace std;

int main()
{
	while (1)
	{
		string str;
		cin >> str;
		if (str == "0") break;
		int ans = str.length() + 1;
		for (char ch : str)
		{
			switch (ch)
			{
			case '0': ans += 4; break;
			case '1': ans += 2; break;
			default: ans += 3; break;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}