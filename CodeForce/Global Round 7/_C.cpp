#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll before = -1;
	ll answer = 1;
	ll N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		ll temp;
		cin >> temp;
		if (temp >= N - K + 1)
		{
			if(before != -1) answer = answer * (i - before) % MOD;
			before = i;
		}
	}
	ll ans = 0;
	for (ll i = N; i > N - K; i--) ans += i;
	cout << ans << ' ' << answer;


	return 0;
}