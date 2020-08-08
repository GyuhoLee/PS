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
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int num[26];
	memset(num, 0, sizeof(num));
	string word;
	cin >> word;
	for (char c : word)
	{
		int temp = (int)c;
		temp -= 97;
		num[temp]++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << num[i] << ' ';
	}

	return 0;
}