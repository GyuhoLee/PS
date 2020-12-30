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

int N, arr[500001], dp[500001];
vector<int> v;
set<int> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, 0);
	CIN(N);
	int M = N;
	while (M--)
	{
		int a, b;
		CIN2(a, b);
		arr[a] = b;
	}
	int idx = 1;
	for (idx; idx <= 500000; idx++)
	{
		if (!arr[idx]) continue;
		v.push_back(arr[idx]);
		break;
	}
	for(idx; idx <= 500000; idx++)
	{
		if (!arr[idx]) continue;
		if (arr[idx] > v.back())
		{
			dp[idx] = v.size();
			v.push_back(arr[idx]);
		}
		else
		{
			int j = lower_bound(ALL(v), arr[idx]) - v.begin();
			v[j] = arr[idx];
			dp[idx] = j;
		}
	}
	int len = v.size();
	FDOWN(i, 500000, 0)
	{
		if (len < 0) break;
		if (!arr[i]) continue;
		if (dp[i] == len - 1)
		{
			ans.insert(i);
			len--;
		}
	}
	COUT(N - v.size());
	ENDL;
	FUP(i, 1, 500000)
	{
		if (!arr[i] || ans.count(i)) continue;
		COUT(i);
		ENDL;
	}

	return 0;
}