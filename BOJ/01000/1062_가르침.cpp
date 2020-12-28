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

int N, K, ans = 0;
map<char, int> ht;
set<char> fix = { 'a', 'c', 'i', 'n', 't' };
string arr[51];
char alpha[21] = { 'b', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'o', 'p', 'q', 'r', 's', 'u', 'v', 'w', 'x', 'y', 'z' };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, K);
	FUP(i, 1, N) CIN(arr[i]);
	K -= 5;
	if (K < 0)
	{
		COUT(0);
		return 0;
	}
	FUP(i, 0, 20) ht[alpha[i]] = i;
	vector<int> permut(21, 0);
	FDOWN(i, 20, 20 - K + 1) permut[i] = 1;
	do
	{
		int cnt = 0;
		FUP(i, 1, N)
		{
			bool ok = true;
			FUP(j, 4, arr[i].length() - 5)
			{
				if (fix.count(arr[i][j])) continue;
				if (!permut[ht[arr[i][j]]])
				{
					ok = false;
					break;
				}
			}
			cnt += ok;
		}
		ans = max(cnt, ans);
	} while (next_permutation(ALL(permut)));
	COUT(ans);

	return 0;
}