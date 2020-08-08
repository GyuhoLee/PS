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
	
	bool ok = false;
	FUP(i, 1, 5)
	{
		string str;
		cin >> str;
		if (str.find("FBI") != string::npos)
		{
			cout << i << '\n';
			ok = true;
		}
	}
	if (!ok) cout << "HE GOT AWAY!";

	return 0;
}