#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int x, y;
		cin >> x >> y;

		int distance = y - x;
		int idx = (int)sqrt(distance);
		int difference = distance - idx*idx;
		int max_distance = idx;
		int move_cnt = 2 * idx - 1;
		int additional_move = 0;
		int total_move_cnt;

		while (1)
		{
			additional_move += difference / max_distance;
			difference = difference % max_distance;
			if (difference == 0) break;
			else max_distance--;
		}

		total_move_cnt = move_cnt + additional_move;
		cout << total_move_cnt << endl;
	}

	return 0;
}