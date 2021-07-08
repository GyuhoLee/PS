#include <iostream>
using namespace std;
#define MOD 14579
long long a, b, num[1001], ans = 1;

int main()
{
	num[1] = 1;
	for (int i = 2; i <= 1000; i++)
		num[i] = (num[i - 1] + i) % MOD;
	cin >> a >> b;
	for (int i = a; i <= b; i++) ans = (ans * num[i]) % MOD;
	cout << ans;

	return 0;
}