#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int temp = b - a - c;
		if (temp > 0) cout << "advertise\n";
		else if (temp == 0) cout << "does not matter\n";
		else cout << "do not advertise\n";
	}


	return 0;
}