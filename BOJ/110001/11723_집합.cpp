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

set<int> S;
int M, x;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(M);
	while (M--)
	{
		CIN(str);
		if (str == "all")
		{
			FUP(i, 1, 20) S.insert(i);
		}
		else if (str == "empty")
		{
			S.clear();
		}
		else
		{
			CIN(x);
			if (str == "add") S.insert(x);
			else if (str == "remove")
			{
				if (S.count(x)) S.erase(S.find(x));
			}
			else if (str == "check")
			{
				COUT(S.count(x));
				ENDL;
			}
			else
			{
				if (S.count(x)) S.erase(S.find(x));
				else S.insert(x);
			}
		}
	}

	return 0;
}