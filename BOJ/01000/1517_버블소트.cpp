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

int N, arr[500000], num[500000];
ll ans = 0;

void merge(int l, int m, int r)
{
	int idx = l;
	int i = l;
	int j = m + 1;
	ll cnt = 0;
	while (i <= m || j <= r)
	{
		if (i > m)
		{
			num[idx++] = arr[j++];
			cnt++;
		}
		else if (j > r)
		{
			num[idx++] = arr[i++];
			ans += cnt;
		}
		else if (arr[i] <= arr[j])
		{
			num[idx++] = arr[i++];
			ans += cnt;
		}
		else
		{
			num[idx++] = arr[j++];
			cnt++;
		}
	}
	FUP(i, l, r) arr[i] = num[i];
}

void mergeSort(int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		merge(l, mid, r);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1) CIN(arr[i]);
	mergeSort(0, N - 1);
	COUT(ans);

	return 0;
}