#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); )
	{
		cout << str[i];
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u') i += 3;
		else i++;
	}

	return 0;
}