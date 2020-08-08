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
	
	string word;
	cin >> word;
	string temp = "";
	vector<string> v;
	for (int i = word.length() - 1; i >= 0; i--)
	{
		temp = word[i] + temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (auto iter: v)
	{
		cout << iter << '\n';
	}

	return 0;
}