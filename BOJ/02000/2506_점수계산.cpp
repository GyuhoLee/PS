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

	int N;
	cin >> N;
	int answer = 0;
	int score = 1;
	while(N--)
	{
		int num;
		cin >> num;
		if (num)
		{
			answer += score;
			score++;
		}
		else score = 1;
	}
	cout << answer;

	return 0;
}