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
#define arr vector<vector<ll>>

ll N, B;
arr A, ans;

arr multi(arr a, arr b)
{
	arr ret(N + 1);
	FUP(i, 1, N)
	{
		ret[i].resize(N + 1);
		FUP(j, 1, N)
		{
			ret[i][j] = 0;
		}
	}
	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			FUP(k, 1, N)
			{
				ret[i][j] += (a[i][k] * b[k][j]);
			}
			ret[i][j] %= 1000;
		}
	}
	return ret;
}

arr solve(arr a, ll x)
{
	if (x == 1) return a;
	arr b = solve(a, x / 2);
	b = multi(b, b);
	if (x % 2) b = multi(b, a);
	return b;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, B);
	A.resize(N + 1);
	FUP(i, 1, N)
	{
		A[i].resize(N + 1);
		FUP(j, 1, N)
		{
			CIN(A[i][j]);
			A[i][j] %= 1000;
		}
	}
	ans = solve(A, B);
	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			COUT2(ans[i][j], "");
		}
		ENDL;
	}

	return 0;
}