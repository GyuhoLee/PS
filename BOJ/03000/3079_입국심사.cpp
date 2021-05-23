#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll N, M, T[100000], ans, l = 1, r;

bool ok(ll t)
{
	ll cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cnt += (t / T[i]);
		if (cnt >= M) return true;
	}
	return false;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> T[i];
	sort(T, T + N);
	r = M * T[N - 1];
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		if (ok(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;

	return 0;
}