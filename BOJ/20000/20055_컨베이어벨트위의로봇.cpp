#include <iostream>
using namespace std;

int N, K, cnt = 0, answer = 0;
pair<int, int> arr[200];

void belt() {
	pair<int, int> tmp = arr[2 * N - 1];
	for (int i = 2 * N - 1; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = tmp;
	arr[N - 1].second = 0;
}

void move() {
	for (int i = N - 2; i >= 0; i--) {
		if (arr[i].second && !arr[i + 1].second && arr[i + 1].first) {
			arr[i].second = 0;
			arr[i + 1].second = 1;
			if (!--arr[i + 1].first) cnt++;
		}
	}
	arr[N - 1].second = 0;
}

void robot() {
	if (arr[0].first) {
		if (!--arr[0].first) cnt++;
		arr[0].second = 1;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		cin >> arr[i].first;
		arr[i].second = 0;
	}

	while (cnt < K) {
		answer++;
		belt();
		move();
		robot();
	}

	cout << answer;

	return 0;
}