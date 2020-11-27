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

int A[31], B[31], D, K;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(D, K);
	A[1] = B[2] = 1;
	A[2] = B[1] = 0;
	FUP(i, 3, D)
	{
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	FUP(i, 1, 100000)
	{
		if ((K - A[D] * i) % B[D] == 0)
		{
			COUT(i);
			ENDL;
			COUT((K - A[D] * i) / B[D]);
			return 0;
		}
	}

	return 0;
}