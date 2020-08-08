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

	string a, b;
	cin >> a >> b;
	int y = 0, x = 0;
	for (int i = 0; i < a.length(); i++)
	{
		bool searching = true;
		for (int j = 0; j < b.length(); j++)
			if (a[i] == b[j])
			{
				y = i;
				x = j;
				searching = false;
				break;
			}
		if (!searching) break;
	}
	for (int i = 0; i < b.length(); i++)
	{
		for (int j = 0; j < a.length(); j++)
			if (j == y && i != x) cout << b[i];
			else if (i == x) cout << a[j];
			else cout << ".";
		cout << "\n";
	}
	return 0;
}