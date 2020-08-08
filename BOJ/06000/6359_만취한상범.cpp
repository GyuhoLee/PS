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
	
	int d[101];
	int num = 2;
	for (int i = 1; i <= 100; i++)
	{
		d[i] = num - 1;
		if (i == num * num)
		{
			d[i] = num;
			num++;
		}
	}
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << d[N] << '\n';
	}

	return 0;
}