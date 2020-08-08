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

	string A, B;
	char c;
	cin >> A >> c >> B;
	int a = A.length();
	int b = B.length();
	if (c == '*')
	{
		cout << 1;
		FUP(i, 1, a + b - 2) cout << 0;
	}
	else
	{
		pair<int, int> num = minmax(a, b);
		if (a == b)
		{
			cout << 2;
			FUP(i, 1, a - 1) cout << 0;
		}
		else
		{
			cout << 1;
			FUP(i, 1, num.second - num.first - 1) cout << 0;
			cout << 1;
			FUP(i, 1, num.first - 1) cout << 0;
		}
		
	}


	return 0;
}