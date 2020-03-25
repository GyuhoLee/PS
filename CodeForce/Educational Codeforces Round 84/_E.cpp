#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long int

ll N;
ll jari[200001];
ll num[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	jari[1] = 10;
	num[1] = 1;

	
	cin >> N;
	for (int i = 2; i <= N; i++) jari[i] = jari[i - 1] * 9 % MOD;
	for (int i = N; i >= 1; i--)
	{
		
	}

	return 0;
}