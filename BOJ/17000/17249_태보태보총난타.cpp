#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	bool is_right = false;
	int ans[2] = { 0, 0 };
	for (char ch : str)
	{
		if (ch == '^') is_right = true;
		if (ch == '@') ans[is_right]++;
	}
	cout << ans[0] << ' ' << ans[1];

	return 0;
}