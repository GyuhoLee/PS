#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
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

	int T;
	cin >> T;
	while (T--)
	{
		int answer = 0;
		string str, str2;
		cin >> str >> str2;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != str2[i]) answer++;
		}
		printf("Hamming distance is %d.\n", answer);
	}
	return 0;
}