#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[1001];
	MS(arr, 0);
	int one[1001];
	int two[1001];
	int L, N;
	cin >> L >> N;
	FUP(i, 1, N)
	{
		int l, r;
		cin >> l >> r;
		one[i] = r - l + 1;
		two[i] = 0;
		FUP(j, l, r)
		{
			if (arr[j]) continue;
			arr[j] = i;
			two[i]++;
		}
	}
	int max = 0;
	int max_idx = 0;
	FUP(i, 1, N)
	{
		if (max < one[i])
		{
			max = one[i];
			max_idx = i;
		}
	}
	cout << max_idx << '\n';

	max = 0;
	max_idx = 0;
	FUP(i, 1, N)
	{
		if (max < two[i])
		{
			max = two[i];
			max_idx = i;
		}
	}
	cout << max_idx << '\n';

	return 0;
}