#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (i < 100) {
			count++;
		}
		else {
			int temp = i;
			int hun = temp / 100;
			int ten = temp / 10 % 10;
			int one = temp % 10;
			if (ten - hun == one - ten)
				count++;
			else if (hun - ten == ten - one)
				count++;
		}
	}
	cout << count << endl;


	return 0;
}