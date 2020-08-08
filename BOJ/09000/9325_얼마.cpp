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

	int T;
	cin >> T;
	while (T--)
	{
		int answer;
		cin >> answer;
		int N;
		cin >> N;
		while (N--)
		{
			int temp, temp2;
			cin >> temp >> temp2;
			answer += (temp * temp2);
		}
		cout << answer << '\n';
	}

	return 0;
}