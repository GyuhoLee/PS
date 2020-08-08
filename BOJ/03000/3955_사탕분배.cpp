#include <bits/stdc++.h>
using namespace std;

long long int T, K, C;

long long int gcd(long long int a, long long int b)
{
	long long int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long extended_gcd(long long A, long long B)
{
	long long r, q, tmpA = A, t, t1 = 0, t2 = 1;
	while (B != 0) 
	{
		q = A / B;
		r = A % B;
		t = t1 - q * t2;
		A = B;
		B = r;
		t1 = t2;
		t2 = t;
	}
	while (t1 < 0) t1 += tmpA;
	return t1;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> K >> C;
		if (C == 1)
		{
			if (K + 1 > 1e9) cout << "IMPOSSIBLE\n";
			else cout << K + 1 << '\n';
			continue;
		}
		else if (K == 1)
		{
			cout << "1\n";
			continue;
		}
		else if (gcd(K, C) != 1)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		long long ans = extended_gcd(K, C);
		if (ans > 1e9) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';

	}

	return 0;
}