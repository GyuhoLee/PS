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

	int arr[100][100];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < 4; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++)
		{
			for (int k = b; k < d; k++)
			{
				arr[j][k] = 1;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			answer += arr[i][j];
		}
	}
	cout << answer;

	return 0;
}