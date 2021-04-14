#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	cout << a * max(b, c) / min(b, c);

	return 0;
}