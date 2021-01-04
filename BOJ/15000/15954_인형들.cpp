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

int N, K;
long double arr[500], ans = LDBL_MAX;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, K);
	FUP(i, 0, N - 1) CIN(arr[i]);
	FUP(k, K, N)
	{
		FUP(i, 0, N - k)
		{
			long double avg = 0, num = 0;
			FUP(j, i, i + k - 1) avg += arr[j];
			avg /= k;

			FUP(j, i, i + k - 1) num += pow(arr[j] - avg, 2);
			num /= k;
			ans = min(ans, num);
		}
	}
	cout << fixed << setprecision(11);
	COUT(sqrt(ans));

	return 0;
}