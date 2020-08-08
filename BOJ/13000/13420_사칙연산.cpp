#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		ll a, b, c;
		char oper, temp;
		string answer = "wrong answer\n";
		cin >> a >> oper >> b >> temp >> c;
		switch (oper)
		{
		case '+':
			if (a + b == c) answer = "correct\n";
			break;
		case '-':
			if (a - b == c) answer = "correct\n";
			break;
		case '*':
			if (a * b == c) answer = "correct\n";
			break;
		case '/':
			if (a / b == c) answer = "correct\n";
			break;
		}
		cout << answer;
	}

	return 0;
}