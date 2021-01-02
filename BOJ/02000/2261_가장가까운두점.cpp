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
#define P pair<int, int>

int N, ans;
P point[100000], a, b;
set<P> S;

int dist(P A, P B)
{
	return pow(A.first - B.first, 2) + pow(A.second - B.second, 2);
}

P rev(P p)
{
	return { p.second, p.first };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1)
	{
		CIN2(point[i].first, point[i].second);
	}
	sort(point, point + N);
	ans = dist(point[0], point[1]);
	S.insert(rev(point[0]));
	S.insert(rev(point[1]));
	int idx = 0;
	FUP(i, 2, N - 1)
	{
		a = point[i];
		while (idx < i)
		{
			b = point[idx];
			if (pow(a.first - b.first, 2) >= ans)
			{
				S.erase(rev(b));
				idx++;
			}
			else break;
		}
		int d = sqrt((double)ans) + 1;
		auto up = S.upper_bound({ a.second + d, 100000 });
		auto low = S.lower_bound({ a.second - d, -100000 });
		while (low != up)
		{
			ans = min(ans, dist(a, rev(*low)));
			low++;
		}
		S.insert(rev(a));
	}
	COUT(ans);


	return 0;
}