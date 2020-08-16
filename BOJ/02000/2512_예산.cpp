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

int N, M;
int arr[10000];

int binary_search()
{
	int left = 1;
	int right = 100000;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		int num = 0;
		FUP(i, 0, N - 1) num += (min(mid, arr[i]));
		if (num == M) 
			return mid;
		if (M < num)
			right = mid - 1;
		else if (M >= num)
			left = mid + 1;
		mid = (left + right) / 2;
	}
	return mid;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1) CIN(arr[i]);
	CIN(M);
	int ans = binary_search();
	sort(arr, arr + N);
	COUT(min(arr[N - 1], ans));

	return 0;
}