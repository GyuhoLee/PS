#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N, M;
	int C = 0;
	float G = 0;
	cin >> N;
	while (N--) {
		C = 0;
		G = 0;
		cin >> M;
		while (M--) {
			int a;
			float b;
			cin >> a >> b;
			C += a;
			G = G + a * b;
		}
		cout << fixed;
		cout.precision(1);
		cout << C << " " <<  G / C << endl;
	}


	return 0;
}