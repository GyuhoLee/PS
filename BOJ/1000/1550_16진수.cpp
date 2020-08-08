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
	
	int num = 0;
	int place = 1;
	string word;
	cin >> word;
	for (int i = word.length() - 1; i >= 0; i--)
	{
		if (word[i] >= 'A' && word[i] <= 'F')
		{
			int temp = word[i] - 'A' + 10;
			num = num + temp * place;
		}
		else
		{
			num = num + (word[i] - '0') * place;
		}
		place *= 16;
	}
	cout << num;
	return 0;
}