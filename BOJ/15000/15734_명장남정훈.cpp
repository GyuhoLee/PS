#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int L, R, A;
	cin >> L >> R >> A;
	if (L > R) swap(L, R);
	while (A && L != R)
	{
		A--;
		L++;
	}
	cout << (min(L, R) + A / 2) * 2;

	return 0;
}