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

int gcd(int x, int y)
{
	if (x < y) swap(x, y);
	int rest;
	while (y)
	{
		rest = x % y;
		x = y;
		y = rest;
	}
	return x;
}

int T, N, arr[1001], cur = 0, idx;
bool visited[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		cur = 0;
		CIN(N);
		FUP(i, 1, N)
		{
			visited[i] = false;
			CIN(arr[i]);
			if (cur < arr[i])
			{
				cur = arr[i];
				idx = i;
			}
		}
		visited[idx] = true;
		COUT(arr[idx]);
		FUP(repeat, 1, N - 1)
		{
			int curGCD = 0;
			FUP(i, 1, N)
			{
				if (visited[i]) continue;
				int tmp = gcd(cur, arr[i]);
				if (tmp > curGCD)
				{
					curGCD = tmp;
					idx = i;
				}
				else if (tmp == curGCD && arr[i] < arr[idx]) idx = i;
			}
			COUT2("", arr[idx]);
			visited[idx] = true;
			cur = curGCD;
		}
		ENDL;
	}

	return 0;
}