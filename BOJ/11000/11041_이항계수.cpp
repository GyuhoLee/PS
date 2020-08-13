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
int MOD = 1e9 + 7;
#define SIZE 4000000

ll N, K, fac[SIZE + 1], inv[SIZE + 1];

ll power(ll x, ll y)
{
    ll ret = 1;
    while (y > 0) 
    {
        if (y % 2)
        {
            ret *= x;
            ret %= MOD;
        }
        x *= x;
        x %= MOD;
        y /= 2;
    }
    return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    fac[1] = 1;
    FUP(i, 2, SIZE) fac[i] = (fac[i - 1] * i) % MOD;
    inv[SIZE] = power(fac[SIZE], MOD - 2);
    FDOWN (i, SIZE - 1, 1) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    
    CIN2(N, K);
    if (N == K || !K) {
        COUT(1);
        return 0;
    }
    ll answer = (fac[N] * inv[N - K]) % MOD;
    answer = (answer * inv[K]) % MOD;
    COUT(answer);

	return 0;
}