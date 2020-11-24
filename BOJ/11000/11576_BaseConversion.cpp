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

int A, B, N, num = 0, tmp;
queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(A, B, N);
	FDOWN(i, N - 1, 0)
	{
		CIN(tmp);
		num += pow(A, i) * tmp;
	}
	tmp = 1;
	while (tmp <= num) { tmp *= B; }
	tmp /= B;
	while (tmp)
	{
		int i = num / tmp;
		Q.push(i);
		num %= tmp;
		tmp /= B;
	}
	while (!Q.empty())
	{
		COUT2(Q.front(), "");
		Q.pop();
	}

	return 0;
}