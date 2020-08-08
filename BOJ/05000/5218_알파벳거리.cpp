#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		string str, str2;
		cin >> str >> str2;
		cout << "Distances:";
		for (int i = 0; i < str.size(); i++)
		{
			cout << ' ' << (26 + str2[i] - str[i]) % 26;
		}
		cout << '\n';
	}

	return 0;
}