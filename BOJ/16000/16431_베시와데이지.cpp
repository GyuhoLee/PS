#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int bx, by, dx, dy, jx, jy;
	cin >> bx >> by >> dx >> dy >> jx >> jy;
	int b = max(abs(jx - bx), abs(jy - by));
	int d = abs(jx - dx) + abs(jy - dy);
	if (b < d) cout << "bessie";
	else if (b > d) cout << "daisy";
	else cout << "tie";

	return 0;
}