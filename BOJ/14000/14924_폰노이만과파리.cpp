#include <iostream>
using namespace std;

int main() {
	int S, T, D;
	cin >> S >> T >> D;
	int time = D / S / 2;
	cout << T * time << endl;

	return 0;
}