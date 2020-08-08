#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		float d = pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
		d = sqrt(d);
		int answer;
		if (r1 + r2 < d) answer = 0;
		else if (r1 + r2 == d) answer = 1;
		else
		{
			int min_r = min(r1, r2);
			int max_r = max(r1, r2);
			if (min_r == max_r)
			{
				if (x1 == x2 && y1 == y2) answer = -1;
				else answer = 2;
			}
			else
			{
				if (min_r + d > max_r) answer = 2;
				else if (min_r + d == max_r) answer = 1;
				else answer = 0;
			}
		}
		cout << answer << endl;
	}
	
}