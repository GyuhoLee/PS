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

int T, N, arr[50], num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	FUP(t, 1, T)
	{
		CIN(N);
		FUP(i, 0, N - 1) CIN(arr[i]);
		num = 0;
		sort(arr, arr + N);
		FUP(i, 0, N - 2) num = max(num, arr[i + 1] - arr[i]);
		COUT2("Class", t);
		ENDL;
		COUT2("Max", arr[N - 1]);
		COUT3(",", "Min", arr[0]);
		COUT3(",", "Largest gap", num);
		ENDL;
	}

	return 0;
}