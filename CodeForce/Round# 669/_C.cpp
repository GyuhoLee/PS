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

int N, arr[10001], L = 1, R = 2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	MS(arr, -1);
	if (N == 1)
	{
		COUT("! 1");
		ENDL;
		cout.flush();
		return 0;
	}
	FUP(repeat, 1, N - 1)
	{
		int lr, rl;
		COUT3('?', L, R);
		ENDL;
		cout.flush();
		CIN(lr);
		COUT3('?', R, L);
		ENDL;
		cout.flush();
		CIN(rl);
		if (lr > rl)
		{
			arr[L] = lr;
			L = R++;
		}
		else
		{
			arr[R] = rl;
			R++;
		}
	}
	COUT('!');
	FUP(i, 1, N)
	{
		arr[i] != -1 ? COUT2("", arr[i]) : COUT2("", N);
	}
	ENDL;
	cout.flush();
	return 0;
}