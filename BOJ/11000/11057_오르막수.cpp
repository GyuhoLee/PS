#include <iostream>
using namespace std;

int num[1001][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++) {
		num[1][i] = 1;
	}
	for (int i = 2; i <= 1000; i++) {
		num[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			num[i][j] = 0;
			for (int k = 0; k <= j; k++) {
				num[i][j] += num[i - 1][k];
			}
			num[i][j] = num[i][j] % 10007;
		}
	}
	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < 10; i++)
		sum += num[N][i];
	cout << sum % 10007;

	return 0;
}