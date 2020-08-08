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
		int a, b;
		cin >> a >> b;
		string str;
		cin >> str;
		for (char ch : str)
		{
			int num = ch - 'A';
			num = a * num + b;
			num %= 26;
			char tmp = num + 'A';
			cout << tmp;
		}
		cout << ENDL;
	}

	return 0;
}