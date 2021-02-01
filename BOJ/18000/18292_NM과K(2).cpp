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

int N, M, K, dp[11][51][1024], arr[11][10], sum[11][1024], kBit[1024], ans = INT_MIN;
set<int> kSet;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(kBit, 0);
	MS(sum, 0);
	CIN3(N, M, K);
	FUP(i, 1, N)
	{
		FUP(j, 0, M - 1)
		{
			CIN(arr[i][j]);
		}
	}
	int m = (1 << M) - 1;
	// k 전처리 (붙어있는 bit 없게)
	FUP(k, 0, m)
	{
		bitset<10> tmp = bitset<10>(k);
		bool ok = true;
		FUP(i, 0, tmp.size() - 2)
		{
			if (tmp[i] && tmp[i + 1]) ok = false;
			if (tmp[i]) kBit[k]++;
		}
		if (tmp[tmp.size() - 1]) kBit[k]++;
		if (ok) kSet.insert(k);
	}
	// COUT(kSet.size()); 10일때 144
	// arr 전처리 (K를 뽑았을 때 i번째의 합)
	FUP(i, 0, N)
	{
		for(int k : kSet)
		{
			FUP(j, 0, M - 1)
			{
				if (k & (1 << j)) sum[i][k] += arr[i][j];
			}
		}
	}
	FUP(i, 0, N)
	{
		FUP(j, 0, K)
		{
			FUP(k, 0, m)
				dp[i][j][k] = INT_MIN;
		}
	}
	dp[0][0][0] = 0;
	FUP(i, 1, N)
	{
		FUP(j, 0, K)
		{
			for(int k : kSet)
			{
				if (j < kBit[k]) continue;
				for(int l : kSet)
				{
					if (!(k & l) && dp[i - 1][j - kBit[k]][l] != INT_MIN)
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - kBit[k]][l] + sum[i][k]);
				}
				if (j == K) ans = max(ans, dp[i][j][k]);
			}
		}
	}
	COUT(ans);


	return 0;
}