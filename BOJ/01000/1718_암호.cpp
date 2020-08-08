#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str, pw;
	getline(cin, str);
	cin >> pw;
	int idx = -1;
	for (char ch : str)
	{
		idx++;
		if (idx == pw.length()) idx = 0;
		if (ch == ' ') cout << ch;
		else
		{
			ch -= pw[idx];
			ch += 'a';
			ch -= 1;
			if (ch < 'a') ch += 26;
			cout << ch;
		}
	}

    return 0;
}