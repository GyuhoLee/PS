#include <iostream>
using namespace std;

int main() {
	int answer[1000001] = { 0, };
	for (int i = 2; i <= 1000000; i++) {
		if (i % 2 == 0) {
			if (answer[i / 2] < answer[i - 1]) answer[i] = answer[i / 2] + 1;
			else answer[i] = answer[i - 1] + 1;
		}
		if (answer[i] != 0) {
			if (i % 3 == 0) {
				if (answer[i] > answer[i / 3]) answer[i] = answer[i / 3] + 1;
			}
		}
		else {
			if (i % 3 == 0) {
				if (answer[i / 3] < answer[i - 1]) {
					answer[i] = answer[i / 3] + 1;
				}
				else {
					answer[i] = answer[i - 1] + 1;
				}
			}
			else answer[i] = answer[i - 1] + 1;
		}
	}
	int N;
	cin >> N;
	cout << answer[N] << endl;

	return 0;
}