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
	//cout.tie(0);

	double Min, x, y;
	int n;
	cin >> x >> y >> n;
	Min = x / y * 1000;
	FUP(i, 0, n - 1)
	{
		double xx, yy;
		cin >> xx >> yy;
		if (Min >= (xx / yy) * 1000)  Min = xx / yy * 1000;
	}
	printf("%.2lf", Min);
	return 0;


	return 0;
}