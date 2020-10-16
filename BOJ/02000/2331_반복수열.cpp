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

int A, P, cnt = 0;
map<int, int> M;

int solve(int num)
{
	int ret = 0;
	while (num)
	{
		int tmp = num % 10;
		num /= 10;
		ret += pow(tmp, P);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(A, P);
	M[A] = 0;
	while (true)
	{
		cnt++;
		A = solve(A);
		if (M.count(A) != 0)
		{
			COUT(M[A]);
			break;
		}
		M[A] = cnt;
	}

	return 0;
}