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
		int N;
		cin >> N;
		string temp;
		getline(cin, temp);
		if (!N) break;
		int idx = 0;
		FUP(xx, 1, N)
		{
			string str;
			getline(cin, str);
			FUP(i, idx, str.size())
			{
				if (i == str.size())
				{
					idx = i;
					break;
				}
				if (str[i] == ' ')
				{
					idx = i;
					break;
				}
			}
		}
		cout << idx + 1 << '\n';
	}
}