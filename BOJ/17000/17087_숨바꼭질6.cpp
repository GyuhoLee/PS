#include <iostream>
using namespace std;

int N, S, A, ans = 0;

int gcd(int x, int y)
{
	if (!y) return x;
	else return gcd(y, x % y);
}

int main()
{
	cin >> N >> S;
	while (N--)
	{
		cin >> A;
		if (ans == 0) ans = abs(S - A);
		else ans = gcd(ans, abs(S - A));
	}
	cout << ans;

	return 0;
}

