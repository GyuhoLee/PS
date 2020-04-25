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

	int T;
	cin >> T;
	while (T--)
	{
		string answer = "NO";
		double N, a, b, c, d;
		cin >> N >> a >> b >> c >> d;
		FUP(i, c - d, c + d)
		{
			if (i / N >= a - b && i / N <= a + b)
			{
				answer = "YES";
				break;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}