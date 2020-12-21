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

int N, arr[11], ans[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(ans, 0);
	CIN(N);
	FUP(i, 1, N)
	{
		CIN(arr[i]);
		int j = 1, cnt = 0;
		while (ans[j]) j++;
		while (cnt != arr[i])
		{
			if (!ans[j]) cnt++;
			j++;
		}
		while (ans[j]) j++;
		ans[j] = i;
	}
	FUP(i, 1, N) COUT2(ans[i], "");

	return 0;
}