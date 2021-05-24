#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	a %= 30;
	if (a * 12 == b) cout << 'O';
	else cout << 'X';

	return 0;
}