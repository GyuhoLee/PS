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

int T, N;
pair<int, int> arr[20];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		vector<int> v;
		CIN(N);
		ll ans = LLONG_MAX;
		FUP(i, 0, N - 1) CIN2(arr[i].first, arr[i].second);
		FUP(i, 1, N / 2) v.push_back(0);
		FUP(i, 1, N / 2) v.push_back(1);
		do
		{
			ll x = 0, y = 0;
			FUP(i, 0, N - 1)
			{
				if (v[i])
				{
					x += arr[i].first;
					y += arr[i].second;
				}
				else
				{
					x -= arr[i].first;
					y -= arr[i].second;
				}
			}
			ans = min(ans, x * x + y * y);
		} while (next_permutation(ALL(v)));
		COUT(fixed);
		cout.precision(20);
		COUT(sqrt(ans));
		ENDL;
	}

	return 0;
}