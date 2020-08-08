#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (!a && !b && !c) break;
		if (b - a == c - b)
		{
			cout << "AP " << c + c - b << '\n';
		}
		else
		{
			cout << "GP " << c * (c / b) << '\n';
		}
	}

	return 0;
}