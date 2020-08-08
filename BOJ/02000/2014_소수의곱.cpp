#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };


int K, N;
int arr[100];
set<ll> S;
priority_queue<ll, vector<ll>, greater<ll>> PQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> N;
	FUP(i, 0, K - 1)
	{
		cin >> arr[i];
	}
	PQ.push(1);
	ll big = 1;
	while (N--)
	{
		ll num = PQ.top();
		PQ.pop();
		FUP(i, 0, K - 1)
		{
			ll temp = num * arr[i];
			if (temp > ((ll)1 << 32) || S.count(temp)) continue;
			if (PQ.size() >= N + 1 && temp >= big) continue;
			big = max(big, temp);
			PQ.push(temp);
			S.insert(temp);
		}
	}
	cout << PQ.top();

	return 0;
}