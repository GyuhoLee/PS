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

	int arr[101];
	arr[1] = 1;
	for (int i = 2; i <= 100; i++) arr[i] = arr[i - 1] + i * i;
	while (true)
	{
		int num;
		cin >> num;
		if (!num) break;
		cout << arr[num] << '\n';
	}

	return 0;
}