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

struct medal
{
	int gold, silver, bronze;
	medal() { gold = silver = bronze = 0; }
	medal(int g, int s, int b) : gold(g), silver(s), bronze(b) {}
	bool operator< (medal x)
	{
		if (gold == x.gold)
		{
			if (silver == x.silver)
			{
				return bronze < x.bronze;
			}
			return silver < x.silver;
		}
		return gold < x.gold;
	}
};

int N, K, a, b, c, d, answer = 1;
medal arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, K);
	FUP(i, 1, N)
	{
		CIN2(a, b);
		CIN2(c, d);
		arr[a] = medal(b, c, d);
	}
	FUP(i, 1, N)
	{
		if (arr[K] < arr[i])
			answer++;
	}
	COUT(answer);

	return 0;
}