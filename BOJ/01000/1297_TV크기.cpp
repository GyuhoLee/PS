#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

ll arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int L, a, b;
	double c, t1, t2;
	cin >> L >> a >> b;
	c = sqrt(a * a + b * b);
	t1 = a * L / c;
	t2 = b * L / c;

	cout << (int)t1 << ' ' << (int)t2;


	return 0;
}