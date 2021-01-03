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

int N, arr[100001], big[100001], small[100001], ans = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	CIN(arr[1]);
	big[1] = small[1] = 1;
	FUP(i, 2, N)
	{
		CIN(arr[i]);
		if (arr[i] >= arr[i - 1]) big[i] = big[i - 1] + 1;
		else big[i] = 1;
		if (arr[i] <= arr[i - 1]) small[i] = small[i - 1] + 1;
		else small[i] = 1;
		ans = max({ ans, small[i], big[i] });
	}
	COUT(ans);

	return 0;
}