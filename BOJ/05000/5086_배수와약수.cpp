#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	while (1)
	{
		int a, b;
		string answer = "neither";
		cin >> a >> b;
		if (a + b == 0) break;
		if (a % b == 0) answer = "multiple";
		else if (b % a == 0) answer = "factor";
		cout << answer << endl;
	}

	return 0;
}