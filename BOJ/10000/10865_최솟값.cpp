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
#define SIZE 100001

int N, M;
ll arr[SIZE], tree[SIZE * 4];

ll init(int idx, int s, int e)
{
	if (s == e)
		return tree[idx] = s;
	int mid = (s + e) / 2;
	int left = init(idx * 2, s, mid);
	int right = init(idx * 2 + 1, mid + 1, e);
	return tree[idx] = arr[left] < arr[right] ? left : right;
}

//sum(1, 1, N, 왼쪽, 오른쪽);
int getMinIdx(int idx, int s, int e, int l, int r)
{
	//[left, right] 범위가 [start, end]와 전혀 겹치지 않는 경우
	if (s > r || e < l)
		return 0;
	//[start, end] 범위가 [left, right]에 완전히 속해 있는 경우
	else if (s >= l && e <= r) return tree[idx];
	ll mid = (s + e) / 2;
	int left = getMinIdx(2 * idx, s, mid, l, r);
	int right = getMinIdx(2 * idx + 1, mid + 1, e, l, r);
	return arr[left] < arr[right] ? left : right;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	arr[0] = 1111111111;
	FUP(i, 1, N) CIN(arr[i]);
	init(1, 1, N);
	while (M--)
	{
		int a, b;
		CIN2(a, b);
		COUT(arr[getMinIdx(1, 1, N, a, b)]);
		ENDL;
	}
	return 0;
}