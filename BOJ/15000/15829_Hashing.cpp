#include <bits/stdc++.h>
using namespace std;
#define MOD 1234567891
#define ll unsigned long long int

int N;
string str;
ll arr[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    arr[0] = 1;
    for(int i = 1; i <= 50; i++) arr[i] = arr[i - 1] * 31 % MOD;
    cin >> N >> str;
    ll answer = 0;
    for(int i = 0; i < N; i++) 
    {
        answer += (arr[i] * ((int)str[i] - 'a' + 1));
        answer %= MOD;
    }
    cout << answer;
    return 0;
}