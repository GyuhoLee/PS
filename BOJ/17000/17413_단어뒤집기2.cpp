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

string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	getline(cin, S);
	bool reverse = true;
	stack<char> st;
	for (char ch : S)
	{
		if (ch == '<')
		{
			while (!st.empty())
			{
				COUT(st.top());
				st.pop();
			}
			COUT(ch);
			reverse = false;
		}
		else if (ch == '>')
		{
			COUT(ch);
			reverse = true;
		}
		else if (ch == ' ')
		{
			while (!st.empty())
			{
				COUT(st.top());
				st.pop();
			}
			COUT(ch);
		}
		else if (reverse)
		{
			st.push(ch);
		}
		else
		{
			COUT(ch);
		}
	}
	while (!st.empty())
	{
		COUT(st.top());
		st.pop();
	}

	return 0;
}