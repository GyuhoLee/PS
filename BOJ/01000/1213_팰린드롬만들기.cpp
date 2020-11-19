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

string str;
int cnt[26];
deque<char> ans;
int odd = 0;
char oddCh;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(cnt, 0);
	CIN(str);
	for (char ch : str)
	{
		cnt[ch - 'A']++;
	}
	
	FUP(i, 0, 25)
	{
		if (cnt[i] % 2 == 1)
		{
			if (str.length() % 2 == 0 || odd != 0)
			{
				COUT("I'm Sorry Hansoo");
				return 0;
			}
			odd++;
			cnt[i]--;
			ans.push_back(i + 'A');
		}
	}
	FDOWN(i, 25, 0)
	{
		FUP(j, 1, cnt[i] / 2)
		{
			ans.push_back(i + 'A');
			ans.push_front(i + 'A');
		}
	}

	for (char ch : ans)
	{
		COUT(ch);
	}

	return 0;
}