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
string dp[101];

string multi(string s)
{
	string ret;
	bool carry = false;
	for (char ch : s)
	{
		int num = ch - '0';
		num = num * 2 + carry;
		carry = num >= 10;
		num %= 10;
		ret += (num + '0');
	}
	if (carry) ret += '1';
	return ret;
}

void hanoi(int num, int from, int to, int remain)
{
	if (num == 1)
	{
		COUT2(from, to);
		ENDL;
		return;
	}
	hanoi(num - 1, from, remain, to);
	COUT2(from, to);
	ENDL;
	hanoi(num - 1, remain, to, from);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[1] = "1";
	FUP(i, 2, 100)
	{
		dp[i] = multi(dp[i - 1]);
		dp[i].front()++;
	}
	CIN(N);
	reverse(ALL(dp[N]));
	COUT(dp[N]);
	ENDL;
	if (N <= 20)
	{
		hanoi(N, 1, 3, 2);
	}


	return 0;
}