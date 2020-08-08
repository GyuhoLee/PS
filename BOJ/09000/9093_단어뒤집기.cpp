#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	getline(cin, str);
	while (N--)
	{
		getline(cin, str);
		int idx = 0;
		FUP(i, 0, str.size() - 1)
		{
			if (str[i] == ' ')
			{
				FDOWN(j, i - 1, idx)
				{
					cout << str[j];
				}
				cout << ' ';
				idx = i + 1;
			}
		}
		FDOWN(i, str.size() - 1, idx) cout << str[i];
		cout << '\n';
	}

	return 0;
}