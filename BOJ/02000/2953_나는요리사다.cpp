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
	
	int answer = 0;
	int idx = 0;
	int arr[4];
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			int temp;
			cin >> temp;
			sum += temp;
		}
		if (answer < sum)
		{
			answer = sum;
			idx = i + 1;
		}
	}
	cout << idx << ' ' << answer;
	

	return 0;
}