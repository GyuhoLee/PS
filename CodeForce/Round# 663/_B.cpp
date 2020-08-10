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

int T, N, M;
string arr[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		int cnt = 0;
		CIN2(N, M);
		FUP(i, 0, N - 1) CIN(arr[i]);
		FUP(i, 0, N - 2)
		{
			if (arr[i][M - 1] == 'R') cnt++;
		}
		FUP(i, 0, M - 2)
		{
			if (arr[N - 1][i] == 'D') cnt++;
		}
		COUT(cnt);
		ENDL;
	}

	return 0;
}