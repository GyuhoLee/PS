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
#define matrix vector<vector<int>>

int N, M, K, ans = INT_MAX;

struct RT
{
	int r, c, s;
	RT() {}
};

RT rt[6];

matrix rotate(matrix arr, int k)
{
	int r = rt[k].r;
	int c = rt[k].c;
	FUP(s, 1, rt[k].s)
	{
		int tmp = arr[r - s + 1][c - s];
		FUP(i, c - s, c + s) swap(arr[r - s][i], tmp);
		FUP(i, r - s + 1, r + s) swap(arr[i][c + s], tmp);
		FDOWN(i, c + s - 1, c - s) swap(arr[r + s][i], tmp);
		FDOWN(i, r + s - 1, r - s + 1) swap(arr[i][c - s], tmp);
	}
	return arr;
}

void solve(matrix arr, int bit)
{
	if (bit + 1 == pow(2, K))
	{
		FUP(i, 1, N)
		{
			int cnt = 0;
			FUP(j, 1, M)
			{
				cnt += arr[i][j];
			}
			ans = min(ans, cnt);
		}
		return;
	}
	FUP(i, 0, K - 1)
	{
		if ((1 << i) & bit) continue;
		solve(rotate(arr, i), bit + (1 << i));
	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, M, K);
	matrix arr(N + 1);
	FUP(i, 1, N)
	{
		arr[i].resize(M + 1);
		FUP(j, 1, M) CIN(arr[i][j]);
	}
	FUP(i, 0, K - 1) CIN3(rt[i].r, rt[i].c, rt[i].s);
	solve(arr, 0);
	COUT(ans);

	return 0;
}