#include <iostream>
#include <string>
using namespace std;

int main()
{
	int idx = 1;
	string str;
	while (true)
	{
		getline(cin, str);
		if (str[1] == 'a') break;
		for (int i = 0; i < str.size(); i += idx + 1) cout << str[i];
		cout << '\n';
		idx++;
	}
}