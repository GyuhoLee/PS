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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int arr[20];
	int temp[20];
	for (int i = 0; i < 20; i++) arr[i] = i + 1;
	int T = 10;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		int j = b;
		for (int i = a; i <= b; i++)
		{
			temp[j] = arr[i];
			j--;
		}
		for (int i = a; i <= b; i++)
		{
			arr[i] = temp[i];
		}
	}
	for (int i = 0; i < 20; i++) cout << arr[i] << ' ';

	return 0;
}