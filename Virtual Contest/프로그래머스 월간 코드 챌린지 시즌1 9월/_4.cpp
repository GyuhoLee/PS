#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#define MOD 10000019
#define ll long long int
using namespace std;
ll fact[301], factInv[301];

ll mpow(ll x, ll m) 
{
    if (!m) return 1;
    ll tmp = mpow(x, m / 2);
    tmp = tmp * tmp % MOD;
    if (m % 2) return tmp * x % MOD;
    return tmp;
}

ll com(ll x, ll r) 
{
    return fact[x] * factInv[r] % MOD * factInv[x - r] % MOD;
}

int solution(vector<vector<int>> a) 
{
    fact[0] = 1;
    for (int i = 1; i <= 300; i++) fact[i] = fact[i - 1] * i % MOD;
    factInv[300] = mpow(fact[300], MOD - 2);
    for (int i = 299;i >= 0;i--) factInv[i] = factInv[i + 1] * (i + 1) % MOD;

    int answer = 0;
    int col[300];
    long long int dp[301][301];
    memset(dp, 0, sizeof(dp));
    memset(col, 0, sizeof(col));
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            col[j] += a[i][j];
        }
    }
    dp[1][col[0]] = com(n, col[0]);
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j] == 0) continue;
            int one = j;
            int two = n - j;
            for (int cnt = 0; cnt <= col[i]; cnt++)
            {
                if (one < cnt || two < col[i] - cnt) continue;
                int ot = com(one, cnt);
                int tt = com(two, col[i] - cnt);
                dp[i + 1][one - cnt + col[i] - cnt] += (dp[i][j] * ot * tt);
                dp[i + 1][one - cnt + col[i] - cnt] %= MOD;
            }
        }
    }
    answer = dp[m][0];

    return answer;
}