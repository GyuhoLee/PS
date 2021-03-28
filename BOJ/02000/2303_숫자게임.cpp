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

int arr[5], cnt = 0, idx = 0;

void solve(int ii)
{
	FUP(i, 0, 2)
	{
		FUP(j, i + 1, 3)
		{
			FUP(k, j + 1, 4)
			{
				int num = (arr[i] + arr[j] + arr[k]) % 10;
				if (num >= cnt)
				{
					cnt = num;
					idx = ii;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	CIN(N);
	FUP(i, 1, N)
	{
		FUP(j, 0, 4) CIN(arr[j]);
		solve(i);
	}
	COUT(idx);

	return 0;
}