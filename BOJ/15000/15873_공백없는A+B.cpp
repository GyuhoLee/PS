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

	string str;
	cin >> str;
	int num = 0;
	if (str.length() == 2)
	{
		num = str[0] + str[1] - '0' - '0';
	}
	else if (str.length() == 4)
	{
		num = 20;
	}
	else if (str[1] == '0')
	{
		num = 10 + str[2] - '0';
	}
	else
	{
		num = str[0] - '0' + 10;
	}
	cout << num;

	return 0;
}