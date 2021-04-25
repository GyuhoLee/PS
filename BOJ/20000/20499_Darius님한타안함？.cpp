#include <iostream>
using namespace std;

int main()
{
	char tmp;
	int K, D, A;
	cin >> K >> tmp >> D >> tmp >> A;
	if (K + A < D || D == 0) cout << "hasu";
	else cout << "gosu";

	return 0;
}