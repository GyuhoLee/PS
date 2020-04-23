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
	int zero = -1;
	int cnt[10];
	MS(cnt, 0);
	int total = 0;
	cin >> str;
	FUP(i, 0, str.length() - 1)
	{
		if (str[i] == '0') zero = i;
		total = total + (int)str[i] - '0';
		cnt[(int)str[i] - '0']++;
	}
	if (total % 3 != 0 || zero == -1)
	{
		cout << -1;
	}
	else
	{
		FDOWN(i, 9, 0)
		{
			FUP(j, 0, cnt[i] - 1)
				cout << i;
		}
	}

	return 0;
}