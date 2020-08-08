#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		ll A, B;
		cin >> A >> B;
		if (!A && !B) break;
		ll sum = A + B;
		ll C = A * 3 - sum;
		cout << C << '\n';
	}
	

	return 0;
}