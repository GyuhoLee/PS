#include <iostream>
using namespace std;

long long int num[91][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	num[1][0] = 0;
	num[1][1] = 1;
	for (int i = 2; i <= 90; i++) {
		num[i][0] = num[i - 1][0] + num[i - 1][1];
		num[i][1] = num[i - 1][0];
	}

	cout << num[N][0] + num[N][1];

	return 0;
}