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
	
	int n;
	cin >> n;
	int arr[3] = { 0, 0, 0 };
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (!arr[2]) arr[2] = arr[1];
	int temp = gcd(arr[0], arr[1]);
	temp = gcd(temp, arr[2]);
	for (int i = 1; i <= temp; i++)
	{
		if (temp % i == 0) cout << i << '\n';
	}


	return 0;
}