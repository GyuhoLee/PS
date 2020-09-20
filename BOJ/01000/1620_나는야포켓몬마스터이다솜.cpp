#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, M;
string arr[100001];
map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 1, N)
	{
		string str;
		CIN(str);
		m[str] = i;
		arr[i] = str;
	}
	while (M--)
	{
		string tmp;
		CIN(tmp);
		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			COUT(arr[stoi(tmp)]);
			ENDL;
		}
		else
		{
			COUT(m[tmp]);
			ENDL;
		}
	}

	return 0;
}