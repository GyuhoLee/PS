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

int T;
string str;
multiset<int> S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		int answer = 0;
		CIN(str);
		int one = 0;
		for(char ch : str)
		{
			if (ch == '1') one++;
			else
			{
				if (one) S.insert(one);
				one = 0;
			}
		}
		if (one) S.insert(one);
		bool ok = true;
		for (auto iter = S.rbegin(); iter != S.rend(); iter++)
		{
			if (ok) answer += *iter;
			ok = !ok;
		}
		COUT(answer);
		ENDL;
		S.clear();
	}

	return 0;
}