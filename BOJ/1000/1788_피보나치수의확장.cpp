#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define MOD 1000000000
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

ll Plus[1000001];
ll Minus[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Plus[0] = 0;
	Plus[1] = 1;
	Minus[0] = 0;
	Minus[1] = 1;
	FUP(i, 2, 1000000)
	{
		Plus[i] = Plus[i - 1] + Plus[i - 2];
		Plus[i] %= MOD;
		Minus[i] = Minus[i - 2] - Minus[i - 1];
		if (Minus[i] > 0) Minus[i] %= MOD;
		else
		{
			Minus[i] *= -1;
			Minus[i] %= MOD;
			Minus[i] *= -1;
		}
	}
	int N;
	cin >> N;
	if (N == 0) cout << "0\n0";
	else if (N > 0) cout << "1\n" << Plus[N];
	else
	{
		N *= -1;
		if (N % 2) cout << "1\n" << Minus[N];
		else cout << "-1\n" << -Minus[N];
	}


	return 0;
}