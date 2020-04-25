#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, K;
int cnt, L;
int arr[200001];
int d[200001];
int Tree[777777];
set<int> S;

int solve(int s, int e)
{
	ll ret = 0;
	while (s <= e)
	{
		if (s % 2) ret += Tree[s];
		if (!(e % 2)) ret += Tree[e];
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		cnt = 1; L = 1;
		MS(d, 0);
		cin >> N >> K;
		FUP(i, 1, N)
		{
			cin >> arr[i];
		}
		FUP(i, 2, N - 1)
		{
			if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) d[i] = 1;
		}
		int H = 1;
		while (H < N) { H *= 2; }
		FUP(i, 0, N - 1) Tree[H + i] = d[i];
		FUP(i, N, H - 1) Tree[H + i] = 0;
		FDOWN(i, H - 1, 1) Tree[i] = Tree[i * 2] + Tree[i * 2 + 1];
		FUP(i, 1, N - K + 1)
		{
			int num = solve(H + i + 1, H + i + K - 2) + 1;
			if (num > cnt)
			{
				cnt = num;
				L = i;
			}
		}
		cout << cnt << ' ' << L << '\n';

	}

	return 0;
}