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

int N;
string tmp, str = "";
vector<string> ans;

bool cmp(string a, string b)
{
	if (a.size() < b.size()) return true;
	else if (a.size() == b.size()) return a < b;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	while (N--)
	{
		str = "";
		CIN(tmp);
		for (char ch : tmp)
		{
			if (ch >= '0' && ch <= '9')
			{
				str += ch;
			}
			else
			{
				if (str != "")
				{
					int i;
					for (i = 0; i < str.length(); i++)
					{
						if (str[i] != '0') break;
					}
					if (i == str.length()) ans.push_back("0");
					else ans.push_back(str.substr(i));
					str = "";
				}
			}
		}
		if (str != "")
		{
			int i;
			for (i = 0; i < str.length(); i++)
			{
				if (str[i] != '0') break;
			}
			if (i == str.length()) ans.push_back("0");
			else ans.push_back(str.substr(i));
		}
	}
	sort(ALL(ans), cmp);
	for (string a : ans)
	{
		COUT(a);
		ENDL;
	}

	return 0;
}