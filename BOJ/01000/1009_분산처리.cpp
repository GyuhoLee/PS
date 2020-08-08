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
		int a, b;
		cin >> a >> b;
		b--;
		int num = a % 10;
		while (b--)
		{
			num = num * a % 10;
		}
		if (!num) num = 10;
		cout << num << '\n';
	}

	return 0;
}