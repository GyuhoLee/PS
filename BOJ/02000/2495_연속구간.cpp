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

	FUP(test_case, 1, 3)
	{
		string str;
		cin >> str;
		int cnt = 1;
		int answer = 1;
		FUP(i, 1, 7)
		{
			if (str[i] == str[i - 1])
			{
				cnt++;
				answer = max(cnt, answer);
			}
			else cnt = 1;
		}
		cout << answer << '\n';
	}


	return 0;
}