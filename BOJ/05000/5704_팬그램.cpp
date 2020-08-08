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

	while (1)
	{
		string str;
		getline(cin, str);
		if (str == "*") break;
		int arr[26];
		MS(arr, 0);
		for (char ch : str)
		{
			if (ch == ' ') continue;
			arr[ch - 'a']++;
		}
		char ans = 'Y';
		FUP(i, 0, 25)
		{
			if (!arr[i]) ans = 'N';
		}
		cout << ans << '\n';
	}


	return 0;
}