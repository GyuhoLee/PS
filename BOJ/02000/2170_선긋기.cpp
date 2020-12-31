#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, ans = 0;
pair<int, int> line[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1) CIN2(line[i].first, line[i].second);
	sort(line, line + N);
	int before = -1e9;
	FUP(i, 0, N - 1)
	{
		if (before <= line[i].first)
		{
			ans += (line[i].second - line[i].first);
			before = line[i].second;
		}
		else if (line[i].second > before)
		{
			ans += (line[i].second - before);
			before = line[i].second;
		}
	}
	COUT(ans);


	return 0;
}