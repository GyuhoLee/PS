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

int N, M, cnt[200001], ans[200001], num;
vector<int> edge[200001], v, tmp;

int half(int idx)
{
	return (edge[idx].size() + 1) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N)
	{
		while (1)
		{
			CIN(num);
			if (!num) break;
			edge[i].push_back(num);
		}
		cnt[i] = 0;
		ans[i] = -1;
	}
	CIN(M);
	while (M--)
	{
		CIN(num);
		ans[num] = 0;
		v.push_back(num);
	}
	int t = 1;
	while (true)
	{
		if (v.empty()) break;
		for (int node : v)
		{
			for (int next : edge[node])
			{
				if (ans[next] != -1) continue;
				if (++cnt[next] >= half(next))
				{
					ans[next] = ans[node] + 1;
					tmp.push_back(next);
				}
			}
		}

		v = tmp;
		tmp.clear();
	}
	FUP(i, 1, N) COUT2(ans[i], "");

	return 0;
}