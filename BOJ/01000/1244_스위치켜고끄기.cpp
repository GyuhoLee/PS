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

int N, arr[101], M, a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N) CIN(arr[i]);
	CIN(M);
	while (M--)
	{
		CIN2(a, b);
		if (a == 1)
		{
			for (int i = b; i <= N; i += b)
			{
				arr[i] ^= 1;
			}
		}
		else
		{
			arr[b] ^= 1;
			int i = 1;
			while (b - i >= 1 && b + i <= N && arr[b - i] == arr[b + i])
			{
				arr[b - i] ^= 1;
				arr[b + i] ^= 1;
				i++;
			}
		}
	}
	FUP(i, 1, N)
	{
		COUT2(arr[i], "");
		if (i % 20 == 0) ENDL;
	}

	return 0;
}