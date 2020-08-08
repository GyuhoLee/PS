#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN1(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT1(a) cout << a
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

	int A, B, C, D, arr[3];
	CIN2(A, B);
	CIN2(C, D);
	CIN3(arr[0], arr[1], arr[2]);
	FUP(i, 0, 2)
	{
		int cnt = 0;
		int num[2] = { arr[i] % (A + B), arr[i] % (C + D) };
		if (num[0] <= A && num[0] != 0) cnt++;
		if (num[1] <= C && num[1] != 0) cnt++;
		COUT1(cnt);
		ENDL;
		
	}

	return 0;
}