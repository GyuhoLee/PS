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
#define SIZE 1000001
#define MOD 1000000007

int N, M, K, T;
ll arr[SIZE], tree[SIZE * 4];

ll init(int idx, int s, int e)
{
	int mid = (s + e) / 2;
	if (s == e) return tree[idx] = arr[s];
	else return tree[idx] = init(idx * 2, s, mid) * init(idx * 2 + 1, mid + 1, e) % MOD;
}


ll multiply(int idx, int s, int e, int l, int r)
{
	//[left, right] 범위가 [start, end]와 전혀 겹치지 않는 경우
	if (s > r || e < l) return 1;
	//[start, end] 범위가 [left, right]에 완전히 속해 있는 경우
	else if (s >= l && e <= r) return tree[idx];
	ll mid = (s + e) / 2;
	return multiply(2 * idx, s, mid, l, r) * multiply(2 * idx + 1, mid + 1, e, l, r) % MOD;
}

ll update(int change, int idx, int s, int e)
{
	if (change < s || change > e) return tree[idx];
	if (s == e) return tree[idx] = arr[s];
	int mid = (s + e) / 2;
	return tree[idx] = update(change, idx * 2, s, mid) * update(change, idx * 2 + 1, mid + 1, e) % MOD;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, M, K);
	FUP(i, 1, N) CIN(arr[i]);
	init(1, 1, N);
	T = M + K;
	while (T--)
	{
		int a, b, c;
		CIN3(a, b, c);
		if (a == 1)
		{
			arr[b] = c;
			update(b, 1, 1, N);
		}
		else
		{
			COUT(multiply(1, 1, N, b, c));
			ENDL;
		}
	}

	return 0;
}