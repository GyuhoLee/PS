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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	CIN(T);
	while (T--)
	{
		//6, 10, 14
		int N;
		CIN(N);
		if (N == 40)
		{
			COUT("YES\n");
			COUT("6 9 10 15");
			ENDL;
		}
		else if (N == 36)
		{
			COUT("YES\n");
			COUT("5 6 10 15");
			ENDL;
		}
		else if (N == 44)
		{
			COUT("YES\n");
			COUT("6 10 13 15");
			ENDL;
		}
		else if (N >= 31)
		{
			COUT("YES\n");
			COUT2("6 10 14", N - 30);
			ENDL;
		}
		else
		{
			COUT("NO\n");
		}
	}

	return 0;
}