#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i <= str.length(); i++)
	{
		if (cnt == 4)
		{
			for (int j = i - 4; j < i; j++) str[j] = 'A';
			cnt = 0;
		}
		if (str[i] == '.' || i == str.length())
		{
			if (cnt == 2)
			{
				str[i - 1] = str[i - 2] = 'B';
				cnt = 0;
			}
			else if (cnt % 2 == 1)
			{
				str = "-1";
				break;
			}
		}
		else cnt++;
	}

	cout << str;
	return 0;
}