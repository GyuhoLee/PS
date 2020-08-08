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
	
	int time = 0;
	for (int i = 0; i < 4; i++)
	{
		int temp;
		cin >> temp;
		time += temp;
	}
	cout << time / 60 << '\n' << time % 60;

	return 0;
}