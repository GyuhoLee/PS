#include <iostream>
using namespace std;

int main()
{
	char word[101];
	cin >> word;
	int i = 0;
	while (1)
	{
		if (word[i] == NULL) break;
		if (word[i] > 64 && word[i] < 97) cout << word[i];
		i++;
	}
	
	return 0;
}