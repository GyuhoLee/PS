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

int N, M, cnt = 0;
string ans = "", arr[1001];
map<char, int> mp;
char ch[4] = { 'A', 'C', 'G', 'T' };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	mp['A'] = 0;
	mp['C'] = 1;
	mp['G'] = 2;
	mp['T'] = 3;

	CIN2(N, M);
	cnt = M * N;
	FUP(i, 1, N) CIN(arr[i]);
	FUP(j, 0, M - 1)
	{
		int d[4] = { 0, 0, 0, 0 };
		FUP(i, 1, N)
		{
			d[mp[arr[i][j]]]++;
		}
		int idx = 0, num = d[0];
		FUP(j, 1, 3)
		{
			if (num < d[j])
			{
				idx = j;
				num = d[j];
			}
		}
		ans += ch[idx];
		cnt -= num;
	}
	COUT(ans);
	ENDL;
	COUT(cnt);

	return 0;
}