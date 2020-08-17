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
int answer = 0;
stack<char> S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(str);

	int num = 1;
	FUP(i, 0, str.size() - 1)
	{
		switch (str[i])
		{
		case '(':
			S.push('(');
			num *= 2;
			break;
		case '[':
			S.push('[');
			num *= 3;
			break;
		case ')':
			if (S.empty() || S.top() != '(')
			{
				COUT(0);
				return 0;
			}
			if (str[i - 1] == '(') answer += num;
			S.pop();
			num /= 2;
			break;
		case ']':
			if (S.empty() || S.top() != '[')
			{
				COUT(0);
				return 0;
			}
			if (str[i - 1] == '[') answer += num;
			S.pop();
			num /= 3;
			break;
		}
	}
	S.empty() ? COUT(answer) : COUT(0);

	return 0;
}