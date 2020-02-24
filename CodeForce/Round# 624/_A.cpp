#include <iostream>
#include <algorithm>
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
		int a, b;
		cin >> a >> b;
		int answer;
		if (a == b) answer = 0;
		else if (a < b)
		{
			int temp = b - a;
			if ((temp - 2) % 4 == 0) answer = 2;
			else if (temp % 2 == 1) answer = 1;
			else answer = 2;
		}
		else
		{
			int temp = a - b;
			if (temp % 2 == 0) answer = 1;
			else answer = 2;
		}
		cout << answer << '\n';
	}

	return 0;
}