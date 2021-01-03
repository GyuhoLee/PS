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

int N, d, k, c, ans = 0, arr[60001];
map<int, int> M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, d);
	CIN2(k, c);
	FUP(i, 1, N)
	{
		CIN(arr[i]);
		arr[i + N] = arr[i];
	}
	FUP(i, 1, k)
	{
		M[arr[i]]++;
	}
	M[c]++;
	ans = M.size();
	FUP(i, k + 1, 2 * N)
	{
		M[arr[i]]++;
		if (--M[arr[i - k]] == 0) M.erase(arr[i - k]);
		ans = max(int(M.size()), ans);
	}
	COUT(ans);

	return 0;
}