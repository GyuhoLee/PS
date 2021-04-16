#include <iostream>
using namespace std;

int main()
{
	int N, L, D, T = 0;
	cin >> N >> L >> D;
	L += 5;
	while (true)
	{
		T += D;
		if (N * L <= T) break;
		if (T % L + 5 >= L) break;
	}
	cout << T;

	return 0;
}