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

int N, ans = 0, num;
map<char, int> M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	while (N--)
	{
		string str;
		CIN(str);
		num = 1;
		for (auto iter = str.rbegin(); iter != str.rend(); iter++)
		{
			M[*iter] += num;
			num *= 10;
		}
	}
	vector<pair<int, char>> v;
	for (auto iter : M)
	{
		v.push_back({ -iter.second, iter.first });
	}
	sort(ALL(v));
	num = 9;
	for (auto p : v)
	{
		ans += (-p.first * num--);
	}
	COUT(ans);
	return 0;
}