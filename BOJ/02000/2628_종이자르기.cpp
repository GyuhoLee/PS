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

int N, M, K;
vector<int> v[2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(M, N, K);
	v[0].push_back(0), v[0].push_back(N);
	v[1].push_back(0), v[1].push_back(M);
	while (K--)
	{
		int a, b;
		CIN2(a, b);
		v[a].push_back(b);
	}
	sort(ALL(v[0])), sort(ALL(v[1]));
	int x = 0, y = 0;
	FUP(i, 1, v[0].size() - 1)
		x = max(x, v[0][i] - v[0][i - 1]);
	FUP(i, 1, v[1].size() - 1)
		y = max(y, v[1][i] - v[1][i - 1]);
	COUT(x * y);

	return 0;
}