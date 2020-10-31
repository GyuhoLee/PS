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

int N, strike, ball;
string num, tmp;
bool arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, true);
	FUP(i, 123, 999)
	{
		int one = i / 100;
		int two = i / 10 % 10;
		int three = i % 10;
		if (one == two || one == three || two == three) arr[i] = false;
		if (one == 0 || two == 0 || three == 0) arr[i] = false;
	}
	CIN(N);
	while (N--)
	{
		CIN3(num, strike, ball);
		FUP(i, 123, 999)
		{
			if (!arr[i]) continue;
			tmp = to_string(i);
			int S = 0, B = 0;
			FUP(i, 0, 2)
			{
				FUP(j, 0, 2)
				{
					if (i == j && num[i] == tmp[j]) S++;
					if (i != j && num[i] == tmp[j]) B++;
				}
			}
			if (S == strike && B == ball) continue;
			arr[i] = false;
		}
	}
	int ans = 0;
	FUP(i, 123, 999)
	{
		if (arr[i]) ans++;
	}
	COUT(ans);


	return 0;
}