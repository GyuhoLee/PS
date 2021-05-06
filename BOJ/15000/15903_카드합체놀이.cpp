#include <iostream>
#include <queue>
using namespace std;
#define ll long long

int main()
{
	ll N, M, num, ans = 0;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	cin >> N >> M;
	while (N--)
	{
		cin >> num;
		pq.push(num);
	}
	while (M--)
	{
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}
	cout << ans;

	return 0;
}