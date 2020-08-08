#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = n / 3;
	int answer = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= n - i - 1; j++)
			answer++;
	}
	cout << answer;

	return 0;
}