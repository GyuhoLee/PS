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

	string str;
	cin >> str;
	int answer = 0;
	for (auto s : str)
	{
		if (s == 'a' || s == 'e' || s == 'o' || s == 'i' || s == 'u') answer++;
	}
	cout << answer;

	return 0;
}