#include <iostream>
using namespace std;

int main()
{
	char word[101];
	cin >> word;
	int i = -1;
	int count = 0;
	while (1)
	{
		i++;
		if (word[i] == NULL) break;
		if (word[i] == '-')	continue;
		else if (word[i] == '=')
		{
			if (i > 1 && word[i - 1] == 'z' && word[i - 2] == 'd')
			{
				count--;
				continue;
			}
		}
		else if (word[i] == 'j')
		{
			if (i != 0 && (word[i - 1] == 'n' || word[i - 1] == 'l')) continue;
			else count++;
		}
		else count++;
	}
	cout << count;
	
	return 0;
}