#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		string str;
		getline(cin, str);
		if (str == "EOI") break;
		for (char& ch : str)
		{
			ch = tolower(ch);
		}
		if (str.find("nemo") != string::npos) cout << "Found\n";
		else cout << "Missing\n";
	}

	return 0;
}