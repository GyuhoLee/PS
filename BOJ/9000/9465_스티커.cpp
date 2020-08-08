#include <iostream>
#include <algorithm>
using namespace std;

long long int num[91][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		int num[100000][2];
		for (int i = 0; i < N; i++)
			cin >> num[i][0];
		for (int i = 0; i < N; i++)
			cin >> num[i][1];
		int big[100000][2];
		big[0][0] = num[0][0];
		big[0][1] = num[0][1];
		big[1][0] = big[0][1] + num[1][0];
		big[1][1] = big[0][0] + num[1][1];
		for (int i = 2; i < N; i++) {
			big[i][0] = max(big[i - 1][1], big[i - 2][1]) + num[i][0];
			big[i][1] = max(big[i - 1][0], big[i - 2][0]) + num[i][1];
		}
		cout << max(big[N - 1][0], big[N - 1][1]) << '\n';


	}

	return 0;
}