#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[1000];
bool check[1001];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= 1000; i++) check[i] = false;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
		if (check[arr[i]]) continue;
		int temp = arr[i];
		while (temp <= N) {
			check[temp] = true;
			temp += arr[i];
		}
	}
	int answer = 0;
	for (int i = 2; i <= N; i++) {
		if (check[i]) answer += i;
	}
	cout << answer;


	return 0;
}