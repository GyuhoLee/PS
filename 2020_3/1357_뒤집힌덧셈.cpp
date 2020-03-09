#include <bits/stdc++.h>
using namespace std;

int Rev(string num)
{
	reverse(num.begin(), num.end());
	return atoi(num.c_str());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string X, Y;
	cin >> X >> Y;
	cout << Rev(to_string(Rev(X) + Rev(Y)));

	return 0;
}