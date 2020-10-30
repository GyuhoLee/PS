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

int N, M, arr[8];

void solve(int bit, int cnt, vector<int> v)
{
	if (cnt == M)
	{
		for (int num : v)
		{
			COUT2(num, "");
		}
		ENDL;
		return;
	}
	int before = -1;
	FUP(i, 0, N - 1)
	{
		if ((bit & (1 << i) )|| before == arr[i]) continue;
		v.push_back(arr[i]);
		solve(bit + (1 << i), cnt + 1, v);
		v.pop_back();
		before = arr[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 0, N - 1) CIN(arr[i]);
	sort(arr, arr + N);
	solve(0, 0, {});

	return 0;
}