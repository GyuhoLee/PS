#include <iostream>
using namespace std;

int main()
{
	int num[2] = { 26, 10 };
	string str;
	cin >> str;
	int ans = num[str[0] - 'c'];
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i - 1]) ans *= (num[str[i] - 'c'] - 1);
		else ans *= num[str[i] - 'c'];
	}
	cout << ans;

	return 0;
}