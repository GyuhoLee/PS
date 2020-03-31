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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, x2, y1, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		bool ok = true;
		if (a > b)
		{
			a -= b;
			if (x - a < x1) ok = false;
		}
		else if (a == b)
		{
			if (x1 == x2 && a > 0) ok = false;
		}
		else
		{
			b -= a;
			if (x + b > x2) ok = false;
		}
		if (c > d)
		{
			c -= d;
			if (y - c < y1) ok = false;
		}
		else if (c == d)
		{
			if (y1 == y2 && c > 0) ok = false;
		}
		else
		{
			d -= c;
			if (y + d > y2) ok = false;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}