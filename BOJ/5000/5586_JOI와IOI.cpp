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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string str;
	cin >> str;
	int I = 0, J = 0;
	for (int i = 0; i < str.size() - 2; i++)
	{
		if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') I++;
		if (str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I') J++;
	}
	cout << J << '\n' << I;

	return 0;
}