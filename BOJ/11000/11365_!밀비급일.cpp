#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	while (1)
	{
		char word[501];
		cin.getline(word, 500);
		if (strcmp(word,"END") == 0) break;
		for (int i = strlen(word) - 1; i >= 0; i--)
		{
			cout << word[i];
		}
		cout << '\n';
	}
	
	return 0;
}