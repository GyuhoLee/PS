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

int N, S, ans = 0, cnt = 0;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, S, str);
	N = (N * 2) + 1;
	cnt = (str[0] == 'I');
	FUP(i, 1, S - 1)
	{
		if (str[i] == str[i - 1])
		{
			if (str[i] == 'I') cnt = 1;
			else cnt = 0;
		}
		else cnt++;
		if (cnt >= N && str[i] == 'I') ans++;
	}
	COUT(ans);
	

	return 0;
}