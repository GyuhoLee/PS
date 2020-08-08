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
	
	int A, B, C;
	cin >> A >> B >> C;
	int car[4] = { 0, A, B, C };
	int arr[101];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < 3; i++)
	{
		int d, e;
		cin >> d >> e;
		for (int j = d; j < e; j++)
		{
			arr[j]++;
		}
	}
	int answer = 0;
	for (int i = 0; i < 100; i++)
	{
		answer += (arr[i] * car[arr[i]]);
	}
	cout << answer;
	return 0;
}