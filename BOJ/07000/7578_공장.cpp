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
#define SIZE 500001

int N, num;
map<int, int> M;
int arr[SIZE];
ll tree[SIZE * 4];

//sum(1, 1, N, 왼쪽, 오른쪽);
ll sum(int idx, int s, int e, int l, int r)
{
	//[left, right] 범위가 [start, end]와 전혀 겹치지 않는 경우
	if (s > r || e < l) return 0;
	//[start, end] 범위가 [left, right]에 완전히 속해 있는 경우
	else if (s >= l && e <= r) return tree[idx];
	int mid = (s + e) / 2;
	return sum(2 * idx, s, mid, l, r) + sum(2 * idx + 1, mid + 1, e, l, r);
}

//update(바뀐 인덱스, 바뀐 값(차이), 1, 1, N);
void update(int change, ll diff, int idx, int s, int e)
{
	if (change < s || change > e) return;
	tree[idx] += diff;
	if (s != e)
	{
		int mid = (s + e) / 2;
		update(change, diff, idx * 2, s, mid);
		update(change, diff, idx * 2 + 1, mid + 1, e);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1)
	{
		CIN(num);
		M[num] = i;
	}
	FUP(i, 0, N - 1)
	{
		CIN(num);
		arr[i] = M[num];
	}
	ll ans = 0;
	FUP(i, 0, N - 1)
	{
		ans += sum(1, 0, N - 1, arr[i] + 1, N - 1);
		update(arr[i], 1, 1, 0, N - 1);
	}
	COUT(ans);


	return 0;
}