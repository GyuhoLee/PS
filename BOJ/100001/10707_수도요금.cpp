#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B, C, D, P;
	cin >> A >> B >> C >> D >> P;
	int X = A * P;
	int temp = P - C;
	int Y = B;
	if (temp > 0) Y += (temp * D);
	cout << min(X, Y);


	return 0;
}