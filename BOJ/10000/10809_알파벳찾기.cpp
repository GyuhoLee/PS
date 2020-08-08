#include <iostream>
#include "string.h"
using namespace std;

int main()
{
	char ch[100];
	cin >> ch;
	int len = strlen(ch);
	for (int i = 'a'; i <= 'z'; i++)
	{
		int answer = -1;
		for (int j = 0; j < len; j++)
		{
			if (char(i) == ch[j])
			{
				answer = j;
				break;
			}
		}
		cout << answer << ' ';
	}

	return 0;
}