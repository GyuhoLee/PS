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
	
	int N;
	string str[100];
	set<string> S;
	cin >> N;
	FUP(i, 0, N - 1)
	{
		cin >> str[i];
		S.insert(str[i]);
	}

	FUP(i, 0, N - 1)
	{
		string tmp = str[i];
		reverse(tmp.begin(), tmp.end());
		if (S.count(tmp))
		{
			cout << tmp.length() << ' ' << tmp[tmp.length() / 2];
			break;
		}
	}

	return 0;
}