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

int N, arr[11], big = INT_MIN, small = INT_MAX;
vector<int> oper(4);

void solve(int num, int idx, vector<int> op)
{
	if (idx == N)
	{
		big = max(big, num);
		small = min(small, num);
		return;
	}
	if (op[0])
	{
		op[0]--;
		solve(num + arr[idx], idx + 1, op);
		op[0]++;
	}
	if (op[1])
	{
		op[1]--;
		solve(num - arr[idx], idx + 1, op);
		op[1]++;
	}
	if (op[2])
	{
		op[2]--;
		solve(num * arr[idx], idx + 1, op);
		op[2]++;
	}
	if (op[3])
	{
		op[3]--;
		solve(num / arr[idx], idx + 1, op);
		op[3]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1) CIN(arr[i]);
	FUP(i, 0, 3) CIN(oper[i]);
	solve(arr[0], 1, oper);
	COUT(big);
	ENDL;
	COUT(small);

	return 0;
}