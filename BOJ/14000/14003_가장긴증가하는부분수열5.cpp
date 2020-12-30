#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, arr[1000000], dp[1000001];
vector<int> v, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, arr[0]);
	v.push_back(arr[0]);
	dp[0] = 0;
	FUP(i, 1, N - 1)
	{
		CIN(arr[i]);
		if (arr[i] > v.back())
		{
			dp[i] = v.size();
			v.push_back(arr[i]);
		}
		else
		{
			int idx = lower_bound(ALL(v), arr[i]) - v.begin();
			v[idx] = arr[i];
			dp[i] = idx;
		}
	}
	COUT(v.size());
	ENDL;
	int len = v.size();
	FDOWN(i, N - 1, 0)
	{
		if (len < 0) break;
		if (dp[i] == len - 1)
		{
			ans.push_back(arr[i]);
			len--;
		}
	}
	FDOWN(i, ans.size() - 1, 0)
	{
		COUT2(ans[i], "");
	}

	return 0;
}