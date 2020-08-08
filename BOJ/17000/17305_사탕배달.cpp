#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int N, W;
ll dp[1250001];
pair<int, int> cnt[1250001];

vector<ll> three;
vector<ll> five;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> W;
	while (N--)
	{
		int a;
		ll b;
		cin >> a >> b;
		if (a == 3) three.push_back(b);
		else five.push_back(b);
	}
	sort(three.begin(), three.end(), greater<int>());
	sort(five.begin(), five.end(), greater<int>());
	dp[0] = dp[1] = dp[2] = 0;
	cnt[0] = cnt[1] = cnt[2] = { 0, 0 };
	for (int i = 3; i <= W; i++)
	{
		dp[i] = dp[i - 1];
		cnt[i] = cnt[i - 1];
		if (cnt[i - 3].first < three.size() && dp[i - 3] + three[cnt[i - 3].first] > dp[i])
		{
			dp[i] = dp[i - 3] + three[cnt[i - 3].first];
			cnt[i] = { cnt[i - 3].first + 1, cnt[i - 3].second };
		}
		if (i >= 5 && cnt[i - 5].second < five.size() && dp[i - 5] + five[cnt[i - 5].second] > dp[i])
		{
			dp[i] = dp[i - 5] + five[cnt[i - 5].second];
			cnt[i] = { cnt[i - 5].first, cnt[i - 5].second + 1 };
		}
	}
	cout << dp[W];
	

	return 0;
}