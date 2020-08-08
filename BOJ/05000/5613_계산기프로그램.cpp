#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;
	while (true)
	{
		char oper;
		cin >> oper;
		if (oper == '=') break;
		int temp;
		cin >> temp;
		if (oper == '+') num += temp;
		else if (oper == '-') num -= temp;
		else if (oper == '*') num *= temp;
		else num /= temp;
	}
	cout << num;

	return 0;
}