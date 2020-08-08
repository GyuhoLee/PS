#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		char word[51];
		cin >> word;
		bool VPS = true;
		int left = 0, right = 0;
		for (int i = 0; i < 50; i++)
		{
			if (word[i] == NULL) break;
			else if (word[i] == '(') left++;
			else if (word[i] == ')') right++;
			if (left < right)
			{
				VPS = false;
				break;
			}
		}
		if (left == right && VPS == true) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}