#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N, K, P;
	cin >> N >> K >> P;
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = answer + (K * i + P * i * i);
	}
	cout << answer;


	return 0;
}