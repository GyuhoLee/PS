#include <iostream>
using namespace std;

int main() {
	int num[10];
	for (int i = 1; i < 10; i++) cin >> num[i];
	for (int i = 1; i < 10; i++) {
		int small = num[i];
		for (int j = i + 1; j < 10; j++) {
			if (small > num[j]) {
				small = num[j];
				num[j] = num[i];
				num[i] = small;
			}
		}
	}
	bool isTrue = false;
	int sum = 0;
	for (int i = 1; i < 10; i++) sum += num[i];
	int two = sum - 100;
	for (int i = 1; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (num[i] + num[j] == two) {
				for (int m = 1; m < 10; m++) {
					if (m == i || m == j) continue;
					else {
						cout << num[m] << endl;
					}
				}
				isTrue = true;
			}
			if (isTrue == true) break;
		}
		if (isTrue == true) break;
	}

	return 0;
}