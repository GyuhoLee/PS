#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int T, N, K;
ll arr[30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		bool ok = true;
		set<ll> s;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			if (!ok) continue;
			ll gop = 1;
			while (arr[i] > gop) { gop *= K; }
			while (arr[i] > 0)
			{
				if (arr[i] / gop == 1)
				{
					if (s.count(gop)) ok = false;
					else s.insert(gop);
				}
				else if (arr[i] / gop > 1) ok = false;
				arr[i] %= gop;
				gop /= K;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}