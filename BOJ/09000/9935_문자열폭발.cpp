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

int idx = 0, N;
string S, B;
char ans[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(S, B);
	N = B.length();
	for (char ch : S)
	{
		ans[idx] = ch;
		if (ch == B[N - 1] && idx >= N - 1)
		{
			bool ok = true;
			FUP(i, 0, N - 1)
			{
				if (ans[idx - i] != B[N - 1 - i])
				{
					ok = false;
					break;
				}
			}
			if (ok) idx -= N;
		}
		idx++;
	}
	if (idx)
	{
		FUP(i, 0, idx - 1) COUT(ans[i]);
	}
	else COUT("FRULA");

	return 0;
}