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

int N;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bool last = true;
	CIN(N);
	arr.resize(N);
	FUP(i, 0, N - 1)
	{
		CIN(arr[i]);
		if (i && arr[i] > arr[i - 1]) last = false;
	}
	if (last)
	{
		COUT(-1);
		return 0;
	}
	next_permutation(ALL(arr));
	FUP(i, 0, N - 1) COUT2(arr[i], "");

	return 0;
}