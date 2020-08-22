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

int a, b, c;

bool judge()
{
	if (a < c && b < 0) return true;
	if (a > c && b > 0) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		CIN3(a, b, c);
		if (!a && !b && !c) break;
		if (a == c)
		{
			COUT("1\n");
			continue;
		}
		if (!b || judge())
		{
			COUT("X\n");
			continue;
		}
		if ((c - a) % b == 0)
		{
			COUT(abs((c - a) / b) + 1);
			ENDL;
		}
		else COUT("X\n");
	}

	return 0;
}