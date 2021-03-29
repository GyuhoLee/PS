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

int T, N, C, cnt[101], arr[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	FUP(t, 1, T)
	{
		cout << "Case #" << t << ": ";
		CIN2(N, C);
		if (N * (N + 1) / 2 - 1 < C || C < N - 1)
		{
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		int num = N;
		int remain = N - 2;
		FUP(i, 1, N) arr[i] = i;
		FUP(i, 1, N - 1)
		{
			if (C - num < remain) cnt[i] = C - remain;
			else cnt[i] = num;
			C -= cnt[i];
			remain--;
			num--;
		}
		FDOWN(i, N - 1, 1)
		{
			reverse(arr + i, arr + i + cnt[i]);
		}
		FUP(i, 1, N) COUT2(arr[i], "");
		ENDL;
	}

	return 0;
}