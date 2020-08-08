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
	
	int N, K;
	cin >> N >> K;
	int arr[2][6];
	memset(arr, 0, sizeof(arr));
	while (N--)
	{
		int S, Y;
		cin >> S >> Y;
		arr[S][Y - 1]++;
	}
	int answer = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			answer += (arr[i][j] / K);
			if (arr[i][j] % K) answer++;
		}
	}
	cout << answer;

	return 0;
}