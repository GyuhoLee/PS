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

int N, C;
int arr[200000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, C);
	FUP(i, 0, N - 1) CIN(arr[i]);
	sort(arr, arr + N);
	int left = 1;
	int right = arr[N - 1] - arr[0];
	int d = 0, ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int s = arr[0];
		int cnt = 1;
		FUP(i, 1, N - 1)
		{
			d = arr[i] - s;
			if (mid <= d)
			{
				cnt++;
				s = arr[i];
			}
		}
		if (cnt >= C)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	COUT(ans);
	return 0;
}