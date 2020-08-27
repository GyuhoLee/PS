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

int T, N, x, arr[100001];
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		bool ok = true;
		CIN2(str, x);
		MS(arr, -1);
		N = str.length();
		FUP(i, 0, N - 1)
		{
			if (str[i] == '0')
			{
				if (i + x < N)
				{
					if (arr[i + x] == 1)
					{
						ok = false;
						break;
					}
					else arr[i + x] = 0;
				}
				if (i - x >= 0)
				{
					if (arr[i - x] == 1)
					{
						ok = false;
						break;
					}
					else arr[i - x] = 0;
				}
			}
			else
			{
				bool go = false;
				if (i - x >= 0)
				{
					if (arr[i - x] != 0)
					{
						arr[i - x] = 1;
						go = true;
					}
				}
				if (!go)
				{
					if (i + x < N && arr[i + x] != 0)
					{
						arr[i + x] = 1;
					}
					else
					{
						ok = false;
						break;
					}
				}
			}
		}
		if (!ok) COUT("-1\n");
		else
		{
			FUP(i, 0, N - 1) arr[i] == -1 ? COUT(0) : COUT(arr[i]);
			ENDL;
		}
	}

	return 0;
}