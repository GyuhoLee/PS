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

string A, B;

string add(string a, string b)
{
	string ret = "";
	if (a.size() < b.size()) swap(a, b);
	int N = a.size();
	bool carry = false;
	FUP(i, 0, N - 1)
	{
		int num = a[i] - '0' + carry;
		carry = false;
		if (i < b.size()) num += b[i] - '0';
		if (num >= 10)
		{
			num -= 10;
			carry = true;
		}
		ret.push_back(num + '0');
	}
	if (carry) ret.push_back('1');
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(A, B);
	reverse(ALL(A)), reverse(ALL(B));
	string ans = add(A, B);
	reverse(ALL(ans));
	COUT(ans);

	return 0;
}