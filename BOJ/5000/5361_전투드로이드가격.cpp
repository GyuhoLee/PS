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
	
	double gun[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
	int T;
	cin >> T;
	while (T--)
	{
		int num[5];
		double answer = 0;
		for (int i = 0; i < 5; i++)
		{
			cin >> num[i];
			answer += (gun[i] * num[i]);
		}
		printf("$%.2f\n", answer);
	}


	return 0;
}