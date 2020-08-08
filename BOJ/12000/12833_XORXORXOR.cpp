#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	while (C--)
	{
		A ^= B;
	}
	cout << A;
	

	return 0;
}