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

	int tc = 0;
	while(1)
	{
		tc++;
		int a, b;
		string oper;
		cin >> a >> oper >> b;
		bool answer = false;
		if (oper == "!=")
		{
			if (a != b) answer = true;
		}
		else if (oper == ">")
		{
			if (a > b) answer = true;
		}
		else if (oper == ">=")
		{
			if (a >= b) answer = true;
		}
		else if (oper == "<")
		{
			if (a < b) answer = true;
		}
		else if (oper == "<=")
		{
			if (a <= b) answer = true;
		}
		else if (oper == "==")
		{
			if (a == b) answer = true;
		}
		else break;
		cout << "Case " << tc << ": ";
		if (answer) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}