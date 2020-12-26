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

int N;
string x = "0", y = "1";

string add(string a, string b)
{
	int n = a.size(), m = b.size();
	string ret(m, '0');
	bool ten = false;


	FUP(i, 0, m - 1)
	{
		int tmp = ten;
		ten = false;
		if (i < n) tmp += a[n - i - 1] - '0';
		if (i < m) tmp += b[m - i - 1] - '0';
		if (tmp >= 10)
		{
			ten = true;
			tmp -= 10;
		}
		ret[m - i - 1] = tmp + '0';
	}
	if (ten) ret = '1' + ret;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	if (N == 0) COUT(x);
	else if (N == 1) COUT(y);
	else
	{
		string ans;
		FUP(i, 1, N - 1)
		{
			ans = add(x, y);
			x = y;
			y = ans;
		}
		COUT(ans);
	}

	return 0;
}