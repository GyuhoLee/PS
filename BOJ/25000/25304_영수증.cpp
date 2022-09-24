#include <iostream>
#include <algorithm>
using namespace std;

int X, N, a, b;

int main() {
	cin >> X >> N;
	while (N--) {
		cin >> a >> b;
		X -= (a * b);
	}
	cout << (X == 0 ? "Yes" : "No");
}