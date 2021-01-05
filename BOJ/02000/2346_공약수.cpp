#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int gcd(int x, int y)
{
	if (x < y) swap(x, y);
	int rest;
	while (y)
	{
		rest = x % y;
		x = y;
		y = rest;
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	CIN2(A, B);
	int num = B / A;
	int x = sqrt(num);
	while (true)
	{
		if (num % x == 0 && gcd(x, num / x) == 1)
		{
			COUT2(A * x, A * (num / x));
			break;
		}
		x--;
	}

	return 0;
}