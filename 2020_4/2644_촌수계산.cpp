#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
int parent[101];
int a, b, x, y;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(parent, 0);
	cin >> N >> a >> b >> M;
	while (M--)
	{
		cin >> x >> y;
		parent[y] = x;
	}
	x = a; y = b;
	int cnt = 0;
	while (x != 0)
	{
		int cnt2 = 0;
		y = b;
		while (y != 0)
		{
			if (x == y)
			{
				cout << cnt + cnt2;
				return 0;
			}
			cnt2++;
			y = parent[y];
		}
		x = parent[x];
		cnt++;
	}
	cout << -1;

	return 0;
}