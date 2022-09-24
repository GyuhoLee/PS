#include <iostream>
using namespace std;

int arr[100][100], N, C, E;

bool check(int i, int j) {
	if (j && arr[i][j - 1] == 1) return false;
	if (j != N - 1 && arr[i][j + 1] == 1) return false;
	if (i && arr[i - 1][j] == 1) return false;
	if (i != N - 1 && arr[i + 1][j] == 1) return false;
	return true;
}

int main() {

	cin >> N >> C >> E;

	if (C + E + 2 > N * N) {
		cout << "-1";
		return 0;
	}

	int i = 0, j = 0, bi = 0, bj = 0;
	while (C--) {
		arr[i][j] = 1;
		if (!j || i == N - 1) {
			i = 0;
			j = ++bj;
			if (j >= N) {
				j = N - 1;
				i = ++bi;
			}
		}
		else {
			j--;
			i++;
		}
	}

	for (i = N - 1; i >= 0 && E; i--) {
		for (j = N - 1; j >= 0 && E; j--) {
			if (check(i, j)) {
				arr[i][j] = 2;
				E--;
			}
		}
	}

	if (E) {
		cout << "-1";
		return 0;
	}

	cout << "1\n";
	for (i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j];
		cout << '\n';
	}

	return 0;
}