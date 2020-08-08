#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

const int MAXN = 1e6 + 3;
bool check[MAXN];
vector<int> prime;
string s;
int k;
bool go(int x) {
    int ret = 0;
    for (int i = 0; s[i]; i++) {
        ret *= 10;
        ret += (s[i] - '0');
        ret %= x;
    }
    return ret == 0;
}
int main() {
    for (int i = 2; i < MAXN; i++) {
        if (!check[i]) {
            prime.push_back(i);
            for (int j = i * 2; j < MAXN; j += i) check[j] = true;
        }
    }
    cin >> s >> k;
    for (int i = 0; i < prime.size(); i++) {
        if (prime[i] >= k) break;
        if (go(prime[i])) {
            printf("BAD %d\n", prime[i]); return 0;
        }
    }
    puts("GOOD");
}
